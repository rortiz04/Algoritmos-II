#include <stdlib.h>
#include <stdio.h>

int min(int a, int b) {
    if (a<=b){
        return(a);
    }
    else {
        return(b);
    }
}

int max(int a, int b) {
    if (a>=b){
        return(a);
    }
    else {
        return(b);
    }
}


int min_temp_hist(WeatherTable array){

    int min_temp = (array[0][0][0])._min_temp;

	for (int year = 0; year < 37; year++){
		for (int month = 0; month < 12; month++){
			for (int day = 0; day <28; day++){
				min_temp = min(min_temp, (array[year][month][day])._min_temp);
			}
		}
	}
	return (min_temp);
}

void max_temp_for_year(WeatherTable array, int output[37]){

	for (unsigned int year = 0u; year < 37; ++year){
		int max_temp = (array[year][0][0]._max_temp);
		for (unsigned int month = 0u; month < 12; ++month){
			for (unsigned int day = 0u; day < 28; ++day){
				max_temp = max(max_temp, (array[year][month][day])._max_temp);
			}
		}
		output[year] = max_temp;
	}
}
