#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

int main()
{
char title[75]="Computer Hardware Graphics Quality Recommendation Tool";
int gpu_clk=0, cpu_clk=0, cpu_core=0, n=0, count=0, ch=0;
float perf_score=0, res_mul=0, high_score=0, low_score=-1;
float mul[4]={ 1, 0.75, 0.55, 0.35 };
char res[4][15]={ {"1280 x 720"}, {"1920 x 1080"}, {"2560 x 1440"}, {"3840 x 2160"} };
char qual[5][15]={ {"Ultra"}, {"High"}, {"Medium"}, {"Low"}, {"Unable to play"} };
cout<<"How many computers are being processed? ";
cin>>n;
cout<<"\n"<<title<<endl;
do
{ cout<<"\nPlease enter the clock speed <in Megahertz> of your graphics card: ";
cin>>gpu_clk;
cout<<"Please enter the clock speed <in Megahertz> of your processor: ";
cin>>cpu_clk;
cout<<"Please enter the number of cores of your processor: ";
cin>>cpu_core;

cout<<"What is the resolution of your monitor?"<<endl;
for(int i=0; i<4; i++)
cout<<"\t"<<i+1<<". "<<res[i]<<endl;
cout<<"Please select from the options above: ";
cin>>ch;
res_mul=mul[ch-1];

perf_score=((5*gpu_clk)+(cpu_core*cpu_clk))*res_mul;

cout<<"GPU Clock Speed: "<<gpu_clk<<endl;
cout<<"CPU Clock Speed: "<<cpu_clk<<endl;
cout<<"Number of cores: "<<cpu_core<<endl;
cout<<"Monitor Resolution: "<<res[ch-1]<<endl;
printf("Performance Score: %.2f",perf_score);
printf("\n");

if(perf_score>17001)
cout<<"Recommended Graphics Quality: "<<qual[0]<<endl;
else if(15001<=perf_score && perf_score<=17000)
cout<<"Recommended Graphics Quality: "<<qual[1]<<endl;
else if(13001<=perf_score && perf_score<=15000)
cout<<"Recommended Graphics Quality: "<<qual[2]<<endl;
else if(11001<=perf_score && perf_score<=13000)
cout<<"Recommended Graphics Quality: "<<qual[3]<<endl;
else
cout<<"Recommended Graphics Quality: "<<qual[4]<<endl;

if(high_score<perf_score)
high_score=perf_score;
if(perf_score<low_score)
low_score=perf_score;
if(count==0)
low_score=perf_score;
perf_score=0;
count++;
}while(count!=n);
cout<<"The highest performance score was: "<<high_score<<endl;
cout<<"The lowest performance score was: "<<low_score;
getch();
return 0;
}
