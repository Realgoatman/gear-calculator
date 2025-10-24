#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* yeah... there's only one flag... */
void checkFlags(int argc, char* argv[])
{
	for(size_t i = 1; i < argc; i += 1)
		if(!strcmp(argv[i], "--help"))
		{
			printf(
					"\nUsage: gear [MODULE] [DIAMETER...]\n\n"

					"This command will help you find the essential of\n"
					"making gear(s) in Build A Boat For Treasure on Roblox.\n\n"

					"NOTE: if the input contain anything that's not number\n"
					"may still parse if the input start with any number.\n"
					"This may not work if the number of teeth is odd (am not sure)\n\n"

					"--help: Show this screen\n\n"
					
					"(I don't really know who tf will read ts tbh)\n\n"
				  );

			exit(0);
		}
}

_Bool range(long double low, long double target, long double high) { return target - low > 0.0L && target - high < 0.0L; }

int main(int argc, char* argv[])
{
	/* preparation */
	checkFlags(argc, argv);
	if(argc <= 2)
	{
		printf("Not enough argumemt provided (use `--help` flag for help)\n");
		exit(1);
	}
	
	/*actual work*/
	long double module = 0.0L, diameter = 0.0L;

	long double data[6]; //{teeth, tooth height, tooth length, scale diameter, scale width, rotation angle}

	if(sscanf(argv[1], "%Lf", &module) != 1)
	{
		printf("Unsuccessfully parse the input module\n");
		exit(1);
	}

	for(size_t i = 2; i < argc; i += 1)
	{
		if(sscanf(argv[i], "%Lf", &diameter) != 1)
		{
			printf("Unsuccessfully parse the %d diameter\n", i);
			exit(1);
		}

		data[0] = diameter / module;
		data[1] = 2.2L * module;
		
		/**/ if(range(4.0L,  data[0], 5.0L))  data[2] = 0.6L * module;
		else if(range(6.0L,  data[0], 7.0L))  data[2] = 0.7L * module;
		else if(range(8.0L,  data[0], 12.0L)) data[2] = 0.8L * module;
		else if(range(13.0L, data[0], 22.0F)) data[2] = 0.9L * module;
		else if(range(23.0L, data[0], 57.0L)) data[2] = /****/ module;
		else /******************************/ data[2] = 1.1L * module;
		
		data[3] = 1.2L * module;
		data[4] = ((diameter - data[3] * 2.0L) * tanl(180.0L / data[0] * M_PI / 180.0L) - 2.0L) / 2.0L;
		data[5] = 360 / data[0];

		printf(
				"\ngear %zu:\n"
					"\tteeth: %.0Lf\n"
					"\ttooth height: %.2Lf (scale by %.2Lf)\n"
					"\ttooth length: %.2Lf (scale by %.2Lf)\n"
					"\tscale the dimeter of the inner circle: %.2Lf\n"
					"\tscale the width of the inner circle: %.2Lf\n"
					"\trotation angle: %.2Lf\n",
			i - 1, data[0], data[1], data[1] - 2.0L, data[2], (data[2] - 2.0L) / 2.0L, data[3], data[4], data[5]
		);
	}
	return 0;
}
