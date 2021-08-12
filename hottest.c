#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <sensors/sensors.h>

static bool is_temperature(const sensors_feature *feat)
{
	return feat->type == SENSORS_FEATURE_TEMP;
}

static bool is_temperature_input(const sensors_subfeature *feat)
{
	return (feat->flags & SENSORS_MODE_R) && (feat->type == SENSORS_SUBFEATURE_TEMP_INPUT);
}

int main(int argc, char **argv)
{
	// parse Arguments

	if (argc <= 0) {
		fputs("hottest: error: malformed argument vector\n", stderr);
		exit(1);
	}

	// initialize library

	if (sensors_init(NULL) != 0) {
		fprintf(stderr, "%s: error: could not initialize sensors library\n", argv[0]);
		exit(1);
	}

	// iterate over all sensors; collect the maximum temperature
	// https://stackoverflow.com/a/8565176

	double max_temp = -INFINITY;

	const sensors_chip_name *cn;
	int c = 0;

	while ((cn = sensors_get_detected_chips(0, &c)) != 0) {
		const sensors_feature *feat;
		int f = 0;

		while ((feat = sensors_get_features(cn, &f)) != 0) {
			if (!is_temperature(feat)) {
				continue;
			}

			const sensors_subfeature *subf;
			int s = 0;

			while ((subf = sensors_get_all_subfeatures(cn, feat, &s)) != 0) {
				if (!is_temperature_input(subf)) {
					continue;
				}

				double current_temp;

				if (sensors_get_value(cn, subf->number, &current_temp) != 0) {
					continue;
				}

				max_temp = fmax(max_temp, current_temp);
			}
		}
	}

	// print the maximum temperature if one was found

	if (isinf(max_temp)) {
		fprintf(stderr, "%s: error: no usable inputs found\n", argv[0]);
		exit(1);
	}

	printf("%0.1f °C\n", max_temp);

	// clean up

	sensors_cleanup();
}
