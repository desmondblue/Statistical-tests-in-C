/*The Following project implements various statistical tests using C programming language
1. Linear Regression
2. Z test
3. T test*/
#include<stdio.h>
#include<stdlib.h> // input output functions
#include<conio.h>
#include<math.h> //for pow() function
/*t test

The test takes value of alpha as 0.05

T = ((sample mean - claimed mean)*square root of n)/standard deviation

*/
void compare_t(int dof, float calculated_t){
int table [32] = {12.706,4.303,3.182,2.776,2.571,2.447,2.365,2.306,2.262,2.228,2.201,2.179,2.16,2.145,2.131,2.12,2.11,2.101,2.093,2.086,2.08,2.074,2.069,2.064,2.06,2.056,2.052,2.048,2.045,2.042,2.021,2};
// t from t table
	float t_table;// value of t from table
	printf("\nTaking alpha(percentile) = 0.05\n");
	if(dof==40){
		t_table = table[30];		
	}
	else if (dof==60){
		t_table = table[31];
	}
	else
		t_table = table[dof-1];
printf("\nValue of t from table : %0.02f\n",t_table);
	if(calculated_t <0){calculated_t*= (-1);}
if(t_table<0){t_table*= (-1);}

	if(t_table>calculated_t){
		printf("\nThe null hypothesis is accepted as the calculated t-value is less than the table value at an alpha level of .05. \nWhich means the p value is greater than alpha level P>0.05");
	}
	else
			printf("\nThe null hypothesis is rejected as the calculated t-value is greater than the table value at an alpha level of .05.\n Which means the p value is greater than alpha level P<0.05");
}
void calc_t(float cm,float sm, float sd, float n){

float t = ((sm-cm)*pow(n,0.5))/sd;
printf("\nCalculated Value of t is %0.02f",t);
	int dof=n-1; //degree of freedom
compare_t(dof,t);	
}
//Z test
void compare_z(double x){
	/*This formula comes from the fact that the normal 
	distribution can be used to approximate the binomial distribution if np and n(1-p) = 5.
	*/
	double alpha = 0.0500;
	if( x<alpha){
	printf("\nThe null hypothesis is rejected as value of P according to Z is less than 0.05\n");
	}
	else
	printf("The null hypothesis is accepted as value of P according to Z is greater than 0.05\n");

getchar();
}
//function declaration
void calc_z(float p, float ps){
	
	int i,j;
	float z; // the value of z will be stored here
	//formulare for the value of z
	z = (ps-p)/pow((p*(1-p))/100,0.5);
	z = floor(100*z)/100;
printf("\nValue of z is %0.4f\n",z);
	

double ztable[70][10]={
0.5000,0.5040,0.5080,0.5120,0.5160,0.5199,0.5239,0.5279,0.5319,0.5359,
0.5398,0.5438,0.5478,0.5517,0.5557,0.5596,0.5636,0.5675,0.5714,0.5753,
0.5793,0.5832,0.5871,0.5910,0.5948,0.5987,0.6026,0.6064,0.6103,0.6141,
0.6179,0.6217,0.6255,0.6293,0.6331,0.6368,0.6406,0.6443,0.6480,0.6517,
0.6554,0.6591,0.6628,0.6664,0.6700,0.6736,0.6772,0.6808,0.6844,0.6879,
0.6915,0.6950,0.6985,0.7019,0.7054,0.7088,0.7123,0.7157,0.7190,0.7224,
0.7257,0.7291,0.7324,0.7357,0.7389,0.7422,0.7454,0.7486,0.7517,0.7549,
0.7580,0.7611,0.7642,0.7673,0.7704,0.7734,0.7764,0.7794,0.7823,0.7852,
0.7881,0.7910,0.7939,0.7967,0.7995,0.8023,0.8051,0.8078,0.8106,0.8133,
0.8159,0.8186,0.8212,0.8238,0.8264,0.8289,0.8315,0.8340,0.8365,0.8389,
0.8413,0.8438,0.8461,0.8485,0.8508,0.8531,0.8554,0.8577,0.8599,0.8621,
0.8643,0.8665,0.8686,0.8708,0.8729,0.8749,0.8770,0.8790,0.8810,0.8830,
0.8849,0.8869,0.8888,0.8907,0.8925,0.8944,0.8962,0.8980,0.8997,0.9015,
0.9032,0.9049,0.9066,0.9082,0.9099,0.9115,0.9131,0.9147,0.9162,0.9177,
0.9192,0.9207,0.9222,0.9236,0.9251,0.9265,0.9279,0.9292,0.9306,0.9319,
0.9332,0.9345,0.9357,0.9370,0.9382,0.9394,0.9406,0.9418,0.9429,0.9441,
0.9452,0.9463,0.9474,0.9484,0.9495,0.9505,0.9515,0.9525,0.9535,0.9545,
0.9554,0.9564,0.9573,0.9582,0.9591,0.9599,0.9608,0.9616,0.9625,0.9633,
0.9641,0.9649,0.9656,0.9664,0.9671,0.9678,0.9686,0.9693,0.9699,0.9706,
0.9713,0.9719,0.9726,0.9732,0.9738,0.9744,0.9750,0.9756,0.9761,0.9767,
0.9772,0.9778,0.9783,0.9788,0.9793,0.9798,0.9803,0.9808,0.9812,0.9817,
0.9821,0.9826,0.9830,0.9834,0.9838,0.9842,0.9846,0.9850,0.9854,0.9857,
0.9861,0.9864,0.9868,0.9871,0.9875,0.9878,0.9881,0.9884,0.9887,0.9890, 
0.9893,0.9896,0.9898,0.9901,0.9904,0.9906,0.9909,0.9911,0.9913,0.9916,
0.9918,0.9920,0.9922,0.9925,0.9927,0.9929,0.9931,0.9932,0.9934,0.9936,
0.9938,0.9940,0.9941,0.9943,0.9945,0.9946,0.9948,0.9949,0.9951,0.9952,
0.9953,0.9955,0.9956,0.9957,0.9959,0.9960,0.9961,0.9962,0.9963,0.9964,
0.9965,0.9966,0.9967,0.9968,0.9969,0.9970,0.9971,0.9972,0.9973,0.9974,
0.9974,0.9975,0.9976,0.9977,0.9977,0.9978,0.9979,0.9979,0.9980,0.9981,
0.9981,0.9982,0.9982,0.9983,0.9984,0.9984,0.9985,0.9985,0.9986,0.9986,
0.9987,0.9987,0.9987,0.9988,0.9988,0.9989,0.9989,0.9989,0.9990,0.9990,
0.9990,0.9991,0.9991,0.9991,0.9992,0.9992,0.9992,0.9992,0.9993,0.9993,
0.9993,0.9993,0.9994,0.9994,0.9994,0.9994,0.9994,0.9995,0.9995,0.9995,
0.9995,0.9995,0.9995,0.9996,0.9996,0.9996,0.9996,0.9996,0.9996,0.9997,
0.9997,0.9997,0.9997,0.9997,0.9997,0.9997,0.9997,0.9997,0.9997,0.9998,
		// z table values for negative numbers 
0.5000,0.4960,0.4920,0.4880,0.4840,0.4801,0.4761,0.4721,0.4681,0.4641,
0.4602,0.4562,0.4522,0.4483,0.4443,0.4404,0.4364,0.4325,0.4286,0.4247,
0.4207,0.4168,0.4129,0.4090,0.4052,0.4013,0.3974,0.3936,0.3897,0.3859,
0.3821,0.3783,0.3745,0.3707,0.3669,0.3632,0.3594,0.3557,0.3520,0.3483,
0.3446,0.3409,0.3372,0.3336,0.3300,0.3264,0.3228,0.3192,0.3156,0.3121,
0.3085,0.3050,0.3015,0.2981,0.2946,0.2912,0.2877,0.2843,0.2810,0.2776,
0.2743,0.2709,0.2676,0.2643,0.2611,0.2578,0.2546,0.2514,0.2483,0.2451,
0.2420,0.2389,0.2358,0.2327,0.2296,0.2266,0.2236,0.2206,0.2177,0.2148,
0.2119,0.2090,0.2061,0.2033,0.2005,0.1977,0.1949,0.1922,0.1894,0.1867,
0.1841,0.1814,0.1788,0.1762,0.1736,0.1711,0.1685,0.1660,0.1635,0.1611,
0.1587,0.1562,0.1539,0.1515,0.1492,0.1469,0.1446,0.1423,0.1401,0.1379,
0.1357,0.1335,0.1314,0.1292,0.1271,0.1251,0.1230,0.1210,0.1190,0.1170,
0.1151,0.1131,0.1112,0.1093,0.1075,0.1056,0.1038,0.1020,0.1003,0.0985,
0.0968,0.0951,0.0934,0.0918,0.0901,0.0885,0.0869,0.0853,0.0838,0.0823,
0.0808,0.0793,0.0778,0.0764,0.0749,0.0735,0.0721,0.0708,0.0694,0.0681,
0.0668,0.0655,0.0643,0.0630,0.0618,0.0606,0.0594,0.0582,0.0571,0.0559,
0.0548,0.0537,0.0526,0.0516,0.0505,0.0495,0.0485,0.0475,0.0465,0.0455,
0.0446,0.0436,0.0427,0.0418,0.0409,0.0401,0.0392,0.0384,0.0375,0.0367,
0.0359,0.0351,0.0344,0.0336,0.0329,0.0322,0.0314,0.0307,0.0301,0.0294,
0.0287,0.0281,0.0274,0.0268,0.0262,0.0256,0.0250,0.0244,0.0239,0.0233,
0.0228,0.0222,0.0217,0.0212,0.0207,0.0202,0.0197,0.0192,0.0188,0.0183,
0.0179,0.0174,0.0170,0.0166,0.0162,0.0158,0.0154,0.0150,0.0146,0.0143,
0.0139,0.0136,0.0132,0.0129,0.0125,0.0122,0.0119,0.0116,0.0113,0.0110,
0.0107,0.0104,0.0102,0.0099,0.0096,0.0094,0.0091,0.0089,0.0087,0.0084,
0.0082,0.0080,0.0078,0.0075,0.0073,0.0071,0.0069,0.0068,0.0066,0.0064,
0.0062,0.0060,0.0059,0.0057,0.0055,0.0054,0.0052,0.0051,0.0049,0.0048,
0.0047,0.0045,0.0044,0.0043,0.0041,0.0040,0.0039,0.0038,0.0037,0.0036,
0.0035,0.0034,0.0033,0.0032,0.0031,0.0030,0.0029,0.0028,0.0027,0.0026,
0.0026,0.0025,0.0024,0.0023,0.0023,0.0022,0.0021,0.0021,0.0020,0.0019,
0.0019,0.0018,0.0018,0.0017,0.0016,0.0016,0.0015,0.0015,0.0014,0.0014,
0.0013,0.0013,0.0013,0.0012,0.0012,0.0011,0.0011,0.0011,0.0010,0.0010,
0.0010,0.0009,0.0009,0.0009,0.0008,0.0008,0.0008,0.0008,0.0007,0.0007,
0.0007,0.0007,0.0006,0.0006,0.0006,0.0006,0.0006,0.0005,0.0005,0.0005,
0.0005,0.0005,0.0005,0.0004,0.0004,0.0004,0.0004,0.0004,0.0004,0.0003,
0.0003,0.0003,0.0003,0.0003,0.0003,0.0003,0.0003,0.0003,0.0003,0.0002};
	
float index[70][10]={0.00,0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.09,0.10,0.11,0.12,0.13,0.14,0.15,0.16,0.17,0.18,0.19,0.20,0.21,0.22,0.23,0.24,0.25,0.26,0.27,0.28,0.29,0.30,0.31,0.32,0.33,0.34,0.35,0.36,0.37,0.38,0.39,0.40,0.41,0.42,0.43,0.44,0.45,0.46,0.47,0.48,0.49,0.50,0.51,0.52,0.53,0.54,0.55,0.56,0.57,0.58,0.59,0.60,0.61,0.62,0.63,0.64,0.65,0.66,0.67,0.68,0.69,0.70,0.71,0.72,0.73,0.74,0.75,0.76,0.77,0.78,0.79,0.80,0.81,0.82,0.83,0.84,0.85,0.86,0.87,0.88,0.89,0.90,0.91,0.92,0.93,0.94,0.95,0.96,0.97,0.98,0.99,1.00,1.01,1.02,1.03,1.04,1.05,1.06,1.07,1.08,1.09,1.10,1.11,1.12,1.13,1.14,1.15,1.16,1.17,1.18,1.19,1.20,1.21,1.22,1.23,1.24,1.25,1.26,1.27,1.28,1.29,1.30,1.31,1.32,1.33,1.34,1.35,1.36,1.37,1.38,1.39,1.40,1.41,1.42,1.43,1.44,1.45,1.46,1.47,1.48,1.49,1.50,1.51,1.52,1.53,1.54,1.55,1.56,1.57,1.58,1.59,1.60,1.61,1.62,1.63,1.64,1.65,1.66,1.67,1.68,1.69,1.70,1.71,1.72,1.73,1.74,1.75,1.76,1.77,1.78,1.79,1.80,1.81,1.82,1.83,1.84,1.85,1.86,1.87,1.88,1.89,1.90,1.91,1.92,1.93,1.94,1.95,1.96,1.97,1.98,1.99,2.00,2.01,2.02,2.03,2.04,2.05,2.06,2.07,2.08,2.09,2.10,2.11,2.12,2.13,2.14,2.15,2.16,2.17,2.18,2.19,2.20,2.21,2.22,2.23,2.24,2.25,2.26,2.27,2.28,2.29,2.30,2.31,2.32,2.33,2.34,2.35,2.36,2.37,2.38,2.39,2.40,2.41,2.42,2.43,2.44,2.45,2.46,2.47,2.48,2.49,2.50,2.51,2.52,2.53,2.54,2.55,2.56,2.57,2.58,2.59,2.60,2.61,2.62,2.63,2.64,2.65,2.66,2.67,2.68,2.69,2.70,2.71,2.72,2.73,2.74,2.75,2.76,2.77,2.78,2.79,2.80,2.81,2.82,2.83,2.84,2.85,2.86,2.87,2.88,2.89,2.90,2.91,2.92,2.93,2.94,2.95,2.96,2.97,2.98,2.99,3.00,3.01,3.02,3.03,3.04,3.05,3.06,3.07,3.08,3.09,3.10,3.11,3.12,3.13,3.14,3.15,3.16,3.17,3.18,3.19,3.20,3.21,3.22,3.23,3.24,3.25,3.26,3.27,3.28,3.29,3.30,3.31,3.32,3.33,3.34,3.35,3.36,3.37,3.38,3.39,3.40,3.41,3.42,3.43,3.44,3.45,3.46,3.47,3.48,3.49,0.00,-0.01,-0.02,-0.03,-0.04,-0.05,-0.06,-0.07,-0.08,-0.09,-0.10,-0.11,-0.12,-0.13,-0.14,-0.15,-0.16,-0.17,-0.18,-0.19,-0.20,-0.21,-0.22,-0.23,-0.24,-0.25,-0.26,-0.27,-0.28,-0.29,-0.30,-0.31,-0.32,-0.33,-0.34,-0.35,-0.36,-0.37,-0.38,-0.39,-0.40,-0.41,-0.42,-0.43,-0.44,-0.45,-0.46,-0.47,-0.48,-0.49,-0.50,-0.51,-0.52,-0.53,-0.54,-0.55,-0.56,-0.57,-0.58,-0.59,-0.60,-0.61,-0.62,-0.63,-0.64,-0.65,-0.66,-0.67,-0.68,-0.69,-0.70,-0.71,-0.72,-0.73,-0.74,-0.75,-0.76,-0.77,-0.78,-0.79,-0.80,-0.81,-0.82,-0.83,-0.84,-0.85,-0.86,-0.87,-0.88,-0.89,-0.90,-0.91,-0.92,-0.93,-0.94,-0.95,-0.96,-0.97,-0.98,-0.99,-1.00,-1.01,-1.02,-1.03,-1.04,-1.05,-1.06,-1.07,-1.08,-1.09,-1.10,-1.11,-1.12,-1.13,-1.14,-1.15,-1.16,-1.17,-1.18,-1.19,-1.20,-1.21,-1.22,-1.23,-1.24,-1.25,-1.26,-1.27,-1.28,-1.29,-1.30,-1.31,-1.32,-1.33,-1.34,-1.35,-1.36,-1.37,-1.38,-1.39,-1.40,-1.41,-1.42,-1.43,-1.44,-1.45,-1.46,-1.47,-1.48,-1.49,-1.50,-1.51,-1.52,-1.53,-1.54,-1.55,-1.56,-1.57,-1.58,-1.59,-1.60,-1.61,-1.62,-1.63,-1.64,-1.65,-1.66,-1.67,-1.68,-1.69,-1.70,-1.71,-1.72,-1.73,-1.74,-1.75,-1.76,-1.77,-1.78,-1.79,-1.80,-1.81,-1.82,-1.83,-1.84,-1.85,-1.86,-1.87,-1.88,-1.89,-1.90,-1.91,-1.92,-1.93,-1.94,-1.95,-1.96,-1.97,-1.98,-1.99,-2.00,-2.01,-2.02,-2.03,-2.04,-2.05,-2.06,-2.07,-2.08,-2.09,-2.10,-2.11,-2.12,-2.13,-2.14,-2.15,-2.16,-2.17,-2.18,-2.19,-2.20,-2.21,-2.22,-2.23,-2.24,-2.25,-2.26,-2.27,-2.28,-2.29,-2.30,-2.31,-2.32,-2.33,-2.34,-2.35,-2.36,-2.37,-2.38,-2.39,-2.40,-2.41,-2.42,-2.43,-2.44,-2.45,-2.46,-2.47,-2.48,-2.49,-2.50,-2.51,-2.52,-2.53,-2.54,-2.55,-2.56,-2.57,-2.58,-2.59,-2.60,-2.61,-2.62,-2.63,-2.64,-2.65,-2.66,-2.67,-2.68,-2.69,-2.70,-2.71,-2.72,-2.73,-2.74,-2.75,-2.76,-2.77,-2.78,-2.79,-2.80,-2.81,-2.82,-2.83,-2.84,-2.85,-2.86,-2.87,-2.88,-2.89,-2.90,-2.91,-2.92,-2.93,-2.94,-2.95,-2.96,-2.97,-2.98,-2.99,-3.00,-3.01,-3.02,-3.03,-3.04,-3.05,-3.06,-3.07,-3.08,-3.09,-3.10,-3.11,-3.12,-3.13,-3.14,-3.15,-3.16,-3.17,-3.18,-3.19,-3.20,-3.21,-3.22,-3.23,-3.24,-3.25,-3.26,-3.27,-3.28,-3.29,-3.30,-3.31,-3.32,-3.33,-3.34,-3.35,-3.36,-3.37,-3.38,-3.39,-3.40,-3.41,-3.42,-3.43,-3.44,-3.45,-3.46,-3.47,-3.48,-3.49,};	
//Since z table only supports values till 3.49 to -3.49
	if(z>3.49||z<-3.49){
		compare_z(ztable[0][0]);
	}

	for( i=0;i<70;i++){
		for(j=0;j<10;j++){
		if( z == index[i][j]){
				
			compare_z(ztable[i][j]);
			}
	}
}
}
//Linear Regression
//structure declaration
struct Point
{
    double x, y;
};

//function declaration
void CalculateRegressionValues(struct Point *points, int count, double *m, double *c)
{
    double Sx = 0.0;
    double Sy = 0.0;
    double Sxx = 0.0;
    double Sxy = 0.0;
    double Syy = 0.0;

    int loop;

    for(loop = 0; loop < count; loop++)
    {
        double x = points[loop].x;
        double y = points[loop].y;

        Sx += x;
        Sy += y;
        Sxx += x*x;
        Sxy += x*y;
        Syy += y*y;
    }
	//formulae for the value of m and c
    *m = (count*Sxy - Sx*Sy) / (count*Sxx - Sx*Sx);
    *c = (Sy - (*m)*Sx) / count;

    printf("Calculated value of m = %lf and calculated value of c = %lf\n", *m, *c);
}

// Main function declaration

int main(){
Mainmenu:
    system("cls");

    struct Point points[10];
    printf("Welcome \nThe following program gives you a brief introduction and implementation of few statistical tests in C");
    printf("\n");
    printf("\nTest List \n1. Linear Regresssion\n2. Z test\n3. T test \nEnter a choice\n");
    int ch ;
    scanf("%d",&ch);
    switch (ch){
        case 1:{
            LRmenu:
                   system("cls");
            printf("\nLinear regression \n1. Introduction\n2.Implementation\nEnter a choice\n");
            int op;
            scanf("%d",&op);
                switch(op){
                    case 1:
                        printf("\nIntroduction\nIn statistics, linear regression is a linear approach for modeling the relationship between a scalar dependent variable y and one or more explanatory variables (or independent variables) denoted X. The case of one explanatory variable is called simple linear regression.");
                        printf("\nEnter 1 to go back to main menu .\nEnter 2 to go back to previous menu \n");
                        int var;
                        scanf("%d",&var);
                        switch(var){
                    case 1:
                        goto Mainmenu;
                        break;
                    case 2:
                        goto LRmenu;
                        break;
                        };
                        break;
                    case 2:

                    printf("\nImplementation of linear regression\n");
                    int count = 10;
                    int loop;
                    double x ;
                    double y;
                    double m, c;
					printf("\nEnter the number of values for X & Y \n");
					scanf("%d",&count);
					printf("\nEnter the values for X & Y\n");
					printf("\n  \tX\tY");
                    for(loop = 0; loop < count; loop++)
                            {printf("\n#%d\t",loop+1);
                                scanf("%lf",&points[loop].x);
                                scanf("%lf",&points[loop].y);
                            }
					printf(" \nSelect Dependent variable (variable to be found)\nX OR Y\n");
					char axe;
					scanf("%s",&axe);
					if(axe == 'y'|| axe == 'Y'){
					 	printf("\nEnter the value of x for which you want to find y :");
						scanf("%lf",&x);
                        CalculateRegressionValues(points, count, &m, &c);
                        y = m*x + c;
                        printf("The calculated value for x = %lf is... y = %lf\n", x, y);}
					else if(axe == 'x'|| axe == 'X'){
						printf("\nEnter the value of y for which you want to find x :");
						scanf("%lf",&y);
                        CalculateRegressionValues(points, count, &m, &c);
                        x=(y-c)/m;
                        printf("The calculated value for y = %lf is... x = %lf\n", x, y);}

                        break;
				       default: printf("invalid choice");
					
	}//End of switch bracket for linear regression
			;break;//End of linear regression case
		}case 2:
		{// Z test introduction and implementation
			ZTmenu:
			system("cls");
			printf("\nZ test\n1.Introduction\n2.Implementation\nEnter choice : ");
			int op;
			scanf("%d",&op);
			switch(op){
				case 1: system("cls");
					printf("\nIntroduction\nA z-test is a statistical test used to determine whether two population means are different when the variances are known and the sample size is large. \nThe test statistic is assumed to have a normal distribution, and nuisance parameters such as standard deviation should be known for an accurate z-test to be performed.");
					printf("\nEnter 1 to go back to main menu .\nEnter 2 to go back to previous menu\n");
                        int var;
                        scanf("%d",&var);
                        switch(var){
                    case 1:
                        goto Mainmenu;
                        break;
                    case 2:
                        goto ZTmenu;
                        break;
                        };
				break;
					case 2:
						//implementation of z test
					printf("\nEnter the population proportion claim (in percentage):");
					float p,x;
					scanf("%f",&p);
					p=p/100;
					printf("\nEnter the sample population size: ");
					float ps;
					scanf("%f",&x);
					printf("\nEnter the sample population proportion: ");
					scanf("%f",&ps);
					ps = ps/x;
					printf("\nNull Hypothesis\nH0 : P = %0.2f(if accepted signifies claim is true)\nH1 : P != %0.2f(i.e. if rejected signifies claim is false)\n",p,p);
					calc_z(p,ps);
					break;
				default: printf("\nIncorrect choice");
		};//End of switch bracket of z test
			break;}//End of Z test case
			//Start of t test
			case 3:
            TTmenu:
                   system("cls");
						
            printf("\nT test \n1. Introduction\n2.Implementation\nEnter a choice\n");
            int op;
            scanf("%d",&op);
                switch(op){
						case 1:
				 		system("cls");
						printf("Introduction\nA t-test is an analysis of two populations means through the use of statistical examination; a t-test with two samples is commonly used with small sample sizes, testing the difference between the samples when the variances of two normal distributions are not known.\nA t-test looks at the t-statistic, the t-distribution and degrees of freedom to determine the probability of difference between populations; the test statistic in the test is known as the t-statistic");
						printf("\nEnter 1 to go back to main menu .\nEnter 2 to go back to previous menu");	
						int var;
                        scanf("%d",&var);
                        switch(var){
                    case 1:
                        goto Mainmenu;
                        break;
                    case 2:
                        goto TTmenu;
                        break;
                        };	
						break;
						case 2:{
							//implementation of t test
						float cm,sm,sd;//claimed mean, observed mean, standard deviation
							float n;
							printf("\nEnter the claimed population mean :");
							scanf("%f",&cm);
							printf("\nEnter size of sample population :");
							scanf("%f",&n);
							printf("\nEnter the sample population mean :");
							scanf("%f",&sm);
							printf("\nThe standard deviation for the sample population :");
							scanf("%f",&sd);
							printf("\nNull Hypothesis\nH0 : mean(u) =%0.2f\n H1: mean(u) != %0.2f\n",cm,cm);
							calc_t(cm,sm,sd,n);
						}
						break;};
		default: printf("\nIncorrect Choice\n");

};
return 0;
}

