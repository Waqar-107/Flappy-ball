# include "iGraphics2.h"

//Start Variable

//colors
#define red 193,0,0
#define green 38,115,67
#define yellow 253,255,49
#define white 255,255,255
#define black 0,0,0
#define red 193,0,0
#define brown 32,42,41
#define sky 175,243,251
#define silver 196,196,196

char plane_name[]="plane1.bmp";
texture buildingtexture;
texture buildingtexture1;
texture buildingtexture2;
texture planetexture;
texture quittexture;
texture quit0texture;
texture high_scoretexture;


void iTextureInit()
{
    buildingtexture.Create("buildings2.bmp");
    buildingtexture1.Create("buildings2(1).bmp");
    buildingtexture2.Create("buildings2(2).bmp");
    planetexture.Create("plane1.bmp");
    quittexture.Create("quit.bmp");
    quit0texture.Create("quit(0).bmp");
    high_scoretexture.Create("highscore.bmp");


}

//constants
#define intro_x 0.450
#define intro_y 0.1

#define dx 40                                                                 //width of the pipes
#define  distance_between_pipes  300                           //vertical distance between two pipes
#define c2y  55                                                                 //55 units higher than the first cloud
#define c3y  70                                                                 //70 units higher than the second cloud
#define c4y  -20                                                               //20 units lower than the third cloud
#define  distance_between_clouds   200                            //horizontal distance between clouds
#define cloud_speed 0.25
#define  reset_pipes_ordinate 1200

//defining the initial position and heights which has been taken arbitrarily
#define pipe_lower_1_arbitrary 1250
#define pipe_lower_2_arbitrary 1500
#define pipe_lower_3_arbitrary 1750
#define pipe_lower_4_arbitrary 2000
#define pipe_lower_5_arbitrary 2250

#define pipe_lower_h1_arbitrary 100
#define pipe_lower_h2_arbitrary  262
#define pipe_lower_h3_arbitrary  70
#define pipe_lower_h4_arbitrary   343
#define pipe_lower_h5_arbitrary   165

//defining the 1st clouds co_ordinates- 6 circles has been drawn overlapping each other to form a cloud
#define cloud_1_x  1
#define cloud_2_x  1.015
#define cloud_3_x  1.020
#define cloud_4_x  1.055
#define cloud_5_x  1.055
#define cloud_6_x  1.075

#define cloud_1_y  0.815
#define cloud_2_y  0.825
#define cloud_3_y  0.810
#define cloud_4_y  0.835
#define cloud_5_y  0.810
#define cloud_6_y  0.815


//reseting position of clouds
#define res_c -25

//building reseting position
#define res_b 1024

//pipe reseting position
#define res_p -50

//blinkers position movement
#define bp 15

//upwards velocity of the ball on each mouse click
#define ball_up 150

//quit button of "game over" screen
#define q_g_x 250
#define q_g_y 350

//positions in "game over" screen
#define score_x  0.5
#define score_y  0.6
#define Name_x 0.4
#define Name_y 0.7
#define SCORE_X 0.4
#define SCORE_Y 0.6
#define play_again_button_x  0.1
#define play_again_button_y 0.2
#define gameover_x 0.4
#define gameover_y 0.5

//positions in "name taking" screen
#define GAMEOVER_F2_X 0.5
#define GAMEOVER_F2_Y 0.7
#define name_takerx 0.25
#define name_takery 0.6
#define ch_f2_X 0.25
#define ch_f2_Y 0.5

//in the game
#define pipe_height_control 400
#define sun_x 0.100
#define sun_y 0.850
#define sun_radius 50
#define building_speed 0.3

//balls speed downwards
#define gravity 0.8

//initial position of ball
#define ball_x 0.2
#define ball_y 0.5

int console_x=1000,console_y=1000;
float plane_x=0,plane_y=console_y*0.9;
float building_x=0,building_y=console_y/3-10;
float building_x1=512,building_y1=console_y/3-10;
float building_x2=1024,building_y2=console_y/3-10;
float building_x3=1536,building_y3=console_y/2-20-10;
int a=0,b=10;
int i;
int score=0;
int t=0;
char Score[1000], name[10], temp[10];


float speed=0.5;

//lower part of the pipes
float pipe_lower_1=pipe_lower_1_arbitrary;
float pipe_lower_2=pipe_lower_2_arbitrary;
float pipe_lower_3=pipe_lower_3_arbitrary;
float pipe_lower_4=pipe_lower_4_arbitrary;
float pipe_lower_5=pipe_lower_5_arbitrary;


float  pipe_lower_height_1=pipe_lower_h1_arbitrary;
float  pipe_lower_height_2=pipe_lower_h2_arbitrary;
float pipe_lower_height_3=pipe_lower_h3_arbitrary;
float  pipe_lower_height_4=pipe_lower_h4_arbitrary;
float  pipe_lower_height_5=pipe_lower_h5_arbitrary;

//upper part- ordinates(y-axis): pipe_upper=pipe_lower_height_n+350
float pipe_upper_1;
float pipe_upper_2;
float pipe_upper_3;
float pipe_upper_4;
float pipe_upper_5;

float pipe_upper_height_1;
float pipe_upper_height_2;
float pipe_upper_height_3;
float pipe_upper_height_4;
float pipe_upper_height_5;

#define radius 25
//cloud1- ordinates and abscissa taken arbitrarily
float c1x1=console_x*cloud_1_x,c1y1=console_y*cloud_1_y;
float c1x2=console_x*cloud_2_x,c1y2=console_y*cloud_2_y;
float c1x3=console_x*cloud_3_x,c1y3=console_y*cloud_3_y;
float c1x4=console_x*cloud_4_x,c1y4=console_y*cloud_4_y;
float c1x5=console_x*cloud_5_x,c1y5=console_y*cloud_5_y;
float c1x6=console_x*cloud_6_x,c1y6=console_y*cloud_6_y;

//cloud2- increasing the value of x by 200 and the value of  y by 55
float c2x1=c1x1+distance_between_clouds, c2y1=c1y1+c2y;
float c2x2=c1x2+distance_between_clouds, c2y2=c1y2+c2y;
float c2x3=c1x3+distance_between_clouds, c2y3=c1y3+c2y;
float c2x4=c1x4+distance_between_clouds, c2y4=c1y4+c2y;
float c2x5=c1x5+distance_between_clouds, c2y5=c1y5+c2y;
float c2x6=c1x6+distance_between_clouds, c2y6=c1y6+c2y;

//cloud3- increasing the value of x by 200 and the value of  y by 70
float c3x1=c2x1+distance_between_clouds,c3y1=c2y1+c3y;
float c3x2=c2x2+distance_between_clouds,c3y2=c2y2+c3y;
float c3x3=c2x3+distance_between_clouds,c3y3=c2y3+c3y;
float c3x4=c2x4+distance_between_clouds,c3y4=c2y4+c3y;
float c3x5=c2x5+distance_between_clouds,c3y5=c2y5+c3y;
float c3x6=c2x6+distance_between_clouds,c3y6=c2y6+c3y;

//cloud4- increasing the value of x by 300 and the value of  y by -20
float c4x1=c3x1+distance_between_clouds,c4y1=c3y1+c4y;
float c4x2=c3x2+distance_between_clouds,c4y2=c3y2+c4y;
float c4x3=c3x3+distance_between_clouds,c4y3=c3y3+c4y;
float c4x4=c3x4+distance_between_clouds,c4y4=c3y4+c4y;
float c4x5=c3x5+distance_between_clouds,c4y5=c3y5+c4y;
float c4x6=c3x6+distance_between_clouds,c4y6=c3y6+c4y;

float x =200, y = 500, r = 20;//Radius of the ball
int flag=-1;
int  flag_score=2;

//two lines drawn for the blinker
int cursor_xs= console_x*0.247,cursor_ys=476;
int cursor_xe=cursor_xs,cursor_ye=cursor_ys+69;

//End of variable

void reset_values(void)
{
    score=0;
    t=0;
    memset(temp,0,sizeof(temp));
    memset(name,0,sizeof(name));

    pipe_lower_1=pipe_lower_1_arbitrary;
    pipe_lower_2=pipe_lower_2_arbitrary;
    pipe_lower_3=pipe_lower_3_arbitrary;
    pipe_lower_4=pipe_lower_4_arbitrary;
    pipe_lower_5=pipe_lower_5_arbitrary;


    pipe_lower_height_1=pipe_lower_h1_arbitrary;
    pipe_lower_height_2=pipe_lower_h2_arbitrary;
    pipe_lower_height_3=pipe_lower_h3_arbitrary;
    pipe_lower_height_4=pipe_lower_h4_arbitrary;
    pipe_lower_height_5=pipe_lower_h5_arbitrary;

    x =console_x*ball_x, y = console_y*ball_y;           //reseting the position of the ball

    cursor_xs= console_x*0.247,cursor_ys=476;           //reseting the blinker
    cursor_xe=cursor_xs,cursor_ye=cursor_ys+69;

    c1x1=console_x*cloud_1_x,c1y1=console_y*cloud_1_y;
    c1x2=console_x*cloud_2_x,c1y2=console_y*cloud_2_y;
    c1x3=console_x*cloud_3_x,c1y3=console_y*cloud_3_y;
    c1x4=console_x*cloud_4_x,c1y4=console_y*cloud_4_y;
    c1x5=console_x*cloud_5_x,c1y5=console_y*cloud_5_y;
    c1x6=console_x*cloud_6_x,c1y6=console_y*cloud_6_y;


    c2x1=c1x1+distance_between_clouds, c2y1=c1y1+c2y;
    c2x2=c1x2+distance_between_clouds, c2y2=c1y2+c2y;
    c2x3=c1x3+distance_between_clouds, c2y3=c1y3+c2y;
    c2x4=c1x4+distance_between_clouds, c2y4=c1y4+c2y;
    c2x5=c1x5+distance_between_clouds, c2y5=c1y5+c2y;
    c2x6=c1x6+distance_between_clouds, c2y6=c1y6+c2y;

    c3x1=c2x1+distance_between_clouds,c3y1=c2y1+c3y;
    c3x2=c2x2+distance_between_clouds,c3y2=c2y2+c3y;
    c3x3=c2x3+distance_between_clouds,c3y3=c2y3+c3y;
    c3x4=c2x4+distance_between_clouds,c3y4=c2y4+c3y;
    c3x5=c2x5+distance_between_clouds,c3y5=c2y5+c3y;
    c3x6=c2x6+distance_between_clouds,c3y6=c2y6+c3y;

    c4x1=c3x1+distance_between_clouds,c4y1=c3y1+c4y;
    c4x2=c3x2+distance_between_clouds,c4y2=c3y2+c4y;
    c4x3=c3x3+distance_between_clouds,c4y3=c3y3+c4y;
    c4x4=c3x4+distance_between_clouds,c4y4=c3y4+c4y;
    c4x5=c3x5+distance_between_clouds,c4y5=c3y5+c4y;
    c4x6=c3x6+distance_between_clouds,c4y6=c3y6+c4y;


}

FILE *fp;
char heading[50]="HIGH SCORES";
void score_records(void)
{
    fp=fopen("High Scores.txt","r+");
    int i = 0;
    int idx;
    int min;
    char name_arr[10][10];
    int arr[10];
    while (fscanf (fp, "%s %d", name_arr[i],&arr[i])!=EOF)
    {
        i++;

    }
    int j=i;
    if(j<10)
    {
        fseek(fp,0L,2);
        fputs(name,fp);
        fputs(" ",fp);
        fputs(Score,fp);
        fputs("\n",fp);
    }
    fclose(fp);
    if(j==10)
    {
        fp=fopen("High Scores.txt","w");
        min=arr[0];
        idx=0;
        for(i=1; i<10; i++)
        {
            if(min>arr[i])
            {
                min=arr[i];
                idx=i;
            }
        }


        if(idx!=0)
        {
            for(i=0; i<idx; i++)
            {
                fputs(name_arr[i],fp);
                fputs(" ",fp);
                fprintf(fp,"%d",arr[i]);
                fputs("\n",fp);
            }
            if(score>=min)
                fprintf(fp,"%s %d\n",name,score);
            else
                fprintf(fp,"%s %d\n",name_arr[idx],arr[idx]);
            for(i=idx+1; i<10; i++)
            {
                fputs(name_arr[i],fp);
                fputs(" ",fp);
                fprintf(fp,"%d",arr[i]);
                fputs("\n",fp);
            }
        }
        else
        {
            fprintf(fp,"%s %d\n",name,score);
            for(i=1; i<10; i++)
            {
                fputs(name_arr[i],fp);
                fputs(" ",fp);
                fprintf(fp,"%d",arr[i]);
                fputs("\n",fp);
            }
        }
        fclose(fp);

    }

}
void high_score()
{
    int idx;
    FILE* file = fopen ("High Scores.txt", "r");
    int i = 0;
    int max=0;
    char hScore[10];
    char name[10][10];
    int arr[10];
    while (fscanf (file, "%s %d", name[i],&arr[i])!=EOF)
    {
        i++;

    }
    int j=i;
    fclose (file);
    for(i=0; i<j; i++)
    {
        if(max<arr[i])
        {
            idx=i;
            max=arr[i];
        }
    }
    itoa(max,hScore,10);
    strcat(name[idx]," ");
    strcat(name[idx],hScore);
    iClear();
    iSetColor(sky);
    iFilledRectangle(0,0,console_x,console_y);
    iSetColor(black);
    iText(console_x*0.1,console_y*0.75,name[idx],GLUT_BITMAP_TIMES_ROMAN_24);
    iText(console_x*0.1,console_y*0.2,"Press Esc to get back to the main menu",GLUT_BITMAP_TIMES_ROMAN_24);
}


int gettime(int t[])
{
    time_t ctime;
    struct tm * current;
    time ( &ctime );
    current = localtime ( &ctime );
    t[0] = current->tm_hour;
    t[1] = current->tm_min;
    t[2] = current->tm_sec;
    return t[2];
}

void timeblinker()
{
    if(flag==-1)
    {
        int time[3]= {};
        int static time1 = gettime(time);
        int time2=gettime(time);
        if((time2-4)%59>=time1%59)
        {
            flag=0;
        }
    }

}

//Main menu
void main_menu()
{

    iClear();
    iSetColor(sky);
    iFilledRectangle(0,0,console_x,console_y);

    iShowBMP(console_x*0.1,console_y*0.75,"play-button.bmp");
    drawTexture(console_x*0.1,console_y*0.55,high_scoretexture);
    drawTexture(console_x*0.25,console_y*.35,quit0texture);


    //static pipes
    iSetColor(green);
    iFilledRectangle(console_x*0.750,0,console_x*0.030,console_y*0.600);
    iFilledRectangle(console_x*0.750,console_y*0.850,console_x*0.030,console_y*0.150);
    iFilledRectangle(console_x*0.650,0,console_x*0.030,console_y*0.450);
    iFilledRectangle(console_x*0.650,console_y*0.750,console_x*0.030,console_y*0.250);


    //cloud1
    iSetColor(white);
    iFilledCircle(c1x1-=cloud_speed,c1y1,radius);
    iFilledCircle(c1x2-=cloud_speed,c1y2,radius);
    iFilledCircle(c1x3-=cloud_speed,c1y3,radius);
    iFilledCircle(c1x4-=cloud_speed,c1y4,radius);
    iFilledCircle(c1x5-=cloud_speed,c1y5,radius);
    iFilledCircle(c1x6-=cloud_speed,c1y6,radius);
    if(c1x6==res_c)
    {
        c1x1=console_x*cloud_1_x;
        c1x2=console_x*cloud_2_x;
        c1x3=console_x*cloud_3_x;
        c1x4=console_x*cloud_4_x;
        c1x5=console_x*cloud_5_x;
        c1x6=console_x*cloud_6_x;
    }


    //cloud2
    iFilledCircle(c2x1-=cloud_speed,c2y1,radius);
    iFilledCircle(c2x2-=cloud_speed,c2y2,radius);
    iFilledCircle(c2x3-=cloud_speed,c2y3,radius);
    iFilledCircle(c2x4-=cloud_speed,c2y4,radius);
    iFilledCircle(c2x5-=cloud_speed,c2y5,radius);
    iFilledCircle(c2x6-=cloud_speed,c2y6,radius);
    if(c2x6==res_c)
    {
        c2x1=c1x1+distance_between_clouds;
        c2x2=c1x2+distance_between_clouds;
        c2x3=c1x3+distance_between_clouds;
        c2x4=c1x4+distance_between_clouds;
        c2x5=c1x5+distance_between_clouds;
        c2x6=c1x6+distance_between_clouds;
    }

    //cloud3
    iFilledCircle(c3x1-=cloud_speed,c3y1,radius);
    iFilledCircle(c3x2-=cloud_speed,c3y2,radius);
    iFilledCircle(c3x3-=cloud_speed,c3y3,radius);
    iFilledCircle(c3x4-=cloud_speed,c3y4,radius);
    iFilledCircle(c3x5-=cloud_speed,c3y5,radius);
    iFilledCircle(c3x6-=cloud_speed,c3y6,radius);
    if(c3x6==res_c)
    {
        c3x1=c2x1+distance_between_clouds;
        c3x2=c2x2+distance_between_clouds;
        c3x3=c2x3+distance_between_clouds;
        c3x4=c2x4+distance_between_clouds;
        c3x5=c2x5+distance_between_clouds;
        c3x6=c2x6+distance_between_clouds;
    }

    //cloud4
    iFilledCircle(c4x1-=cloud_speed,c4y1,radius);
    iFilledCircle(c4x2-=cloud_speed,c4y2,radius);
    iFilledCircle(c4x3-=cloud_speed,c4y3,radius);
    iFilledCircle(c4x4-=cloud_speed,c4y4,radius);
    iFilledCircle(c4x5-=cloud_speed,c4y5,radius);
    iFilledCircle(c4x6-=cloud_speed,c4y6,radius);
    if(c4x6==res_c)
    {
        c4x1=c3x1+distance_between_clouds;
        c4x2=c3x2+distance_between_clouds;
        c4x3=c3x3+distance_between_clouds;
        c4x4=c3x4+distance_between_clouds;
        c4x5=c3x5+distance_between_clouds;
        c4x6=c3x6+distance_between_clouds;
    }

}
//End Function-Main_menu

//intoGame
void intoGame()
{
    iClear();

    //color of the console
    iSetColor(sky);
    iFilledRectangle(0,0,console_x,console_y);

    //iShowBMP(0,console_y/2,"rainbow.bmp");
    //building

    if(building_x<=-res_b/2)
    {
        building_x=res_b;
    }
    if(building_x1<=-res_b/2)
    {
        building_x1=res_b;
    }
    if(building_x2<=-res_b/2)
    {
        building_x2=res_b;
    }

    drawTexture(building_x-=building_speed,building_y,buildingtexture);
    drawTexture(building_x1-=building_speed,building_y1,buildingtexture1);
    drawTexture(building_x2-=building_speed,building_y2,buildingtexture2);
    iSetColor(brown);
    iFilledRectangle(0,0,console_x,console_y/3);

    //AIRPlane
    drawTexture(plane_x+=0.3,plane_y,planetexture);
    if(plane_x>=console_x*2)
    {
        plane_x=-console_x*0.128;
    }

    //sun
    iSetColor(yellow);
    iFilledCircle(console_x*sun_x,console_y*sun_y,sun_radius);


    //cloud1
    iSetColor(white);
    iFilledCircle(c1x1-=cloud_speed,c1y1,radius);
    iFilledCircle(c1x2-=cloud_speed,c1y2,radius);
    iFilledCircle(c1x3-=cloud_speed,c1y3,radius);
    iFilledCircle(c1x4-=cloud_speed,c1y4,radius);
    iFilledCircle(c1x5-=cloud_speed,c1y5,radius);
    iFilledCircle(c1x6-=cloud_speed,c1y6,radius);
    if(c1x6==res_c)
    {
        c1x1=console_x*cloud_1_x;
        c1x2=console_x*cloud_2_x;
        c1x3=console_x*cloud_3_x;
        c1x4=console_x*cloud_4_x;
        c1x5=console_x*cloud_5_x;
        c1x6=console_x*cloud_6_x;
    }


    //cloud2
    iFilledCircle(c2x1-=cloud_speed,c2y1,radius);
    iFilledCircle(c2x2-=cloud_speed,c2y2,radius);
    iFilledCircle(c2x3-=cloud_speed,c2y3,radius);
    iFilledCircle(c2x4-=cloud_speed,c2y4,radius);
    iFilledCircle(c2x5-=cloud_speed,c2y5,radius);
    iFilledCircle(c2x6-=cloud_speed,c2y6,radius);
    if(c2x6==res_c)
    {
        c2x1=c1x1+distance_between_clouds;
        c2x2=c1x2+distance_between_clouds;
        c2x3=c1x3+distance_between_clouds;
        c2x4=c1x4+distance_between_clouds;
        c2x5=c1x5+distance_between_clouds;
        c2x6=c1x6+distance_between_clouds;
    }

    //cloud3
    iFilledCircle(c3x1-=cloud_speed,c3y1,radius);
    iFilledCircle(c3x2-=cloud_speed,c3y2,radius);
    iFilledCircle(c3x3-=cloud_speed,c3y3,radius);
    iFilledCircle(c3x4-=cloud_speed,c3y4,radius);
    iFilledCircle(c3x5-=cloud_speed,c3y5,radius);
    iFilledCircle(c3x6-=cloud_speed,c3y6,radius);
    if(c3x6==res_c)
    {
        c3x1=c2x1+distance_between_clouds;
        c3x2=c2x2+distance_between_clouds;
        c3x3=c2x3+distance_between_clouds;
        c3x4=c2x4+distance_between_clouds;
        c3x5=c2x5+distance_between_clouds;
        c3x6=c2x6+distance_between_clouds;
    }

    //cloud4
    iFilledCircle(c4x1-=cloud_speed,c4y1,radius);
    iFilledCircle(c4x2-=cloud_speed,c4y2,radius);
    iFilledCircle(c4x3-=cloud_speed,c4y3,radius);
    iFilledCircle(c4x4-=cloud_speed,c4y4,radius);
    iFilledCircle(c4x5-=cloud_speed,c4y5,radius);
    iFilledCircle(c4x6-=cloud_speed,c4y6,radius);
    if(c4x6==res_c)
    {
        c4x1=c3x1+distance_between_clouds;
        c4x2=c3x2+distance_between_clouds;
        c4x3=c3x3+distance_between_clouds;
        c4x4=c3x4+distance_between_clouds;
        c4x5=c3x5+distance_between_clouds;
        c4x6=c3x6+distance_between_clouds;
    }



    //color and position of the ball
    iSetColor((a+=1)%255, (b+=1)%255, 200);
    iFilledCircle(x, y=y-gravity, r);

    //lower part
    iSetColor(silver);
    if(pipe_lower_1==res_p)
    {
        pipe_lower_1=reset_pipes_ordinate;
        pipe_lower_height_1=rand()%pipe_height_control;
    }
    iFilledRectangle(pipe_lower_1-=speed, 0, dx, pipe_lower_height_1);

    if(pipe_lower_2==res_p)
    {
        pipe_lower_2=reset_pipes_ordinate;
        pipe_lower_height_2=rand()%pipe_height_control;
    }
    iFilledRectangle(pipe_lower_2-=speed, 0, dx,pipe_lower_height_2);

    if(pipe_lower_3==res_p)
    {
        pipe_lower_3=reset_pipes_ordinate;
        pipe_lower_height_3=rand()%pipe_height_control;
    }
    iFilledRectangle(pipe_lower_3-=speed, 0, dx,pipe_lower_height_3);

    if(pipe_lower_4==res_p)
    {
        pipe_lower_4=reset_pipes_ordinate;
        pipe_lower_height_4=rand()%pipe_height_control;
    }
    iFilledRectangle(pipe_lower_4-=speed, 0, dx,pipe_lower_height_4);

    if(pipe_lower_5==res_p)
    {
        pipe_lower_5=reset_pipes_ordinate;
        pipe_lower_height_5=rand()%pipe_height_control;
    }
    iFilledRectangle(pipe_lower_5-=speed, 0, dx,pipe_lower_height_5);


    //upper part
    iFilledRectangle(pipe_lower_1-=speed, pipe_upper_1=pipe_lower_height_1+distance_between_pipes, dx,pipe_upper_height_1=console_y-pipe_upper_1);

    iFilledRectangle(pipe_lower_2-=speed, pipe_upper_2=pipe_lower_height_2+distance_between_pipes, dx,pipe_upper_height_2=console_y-pipe_upper_2);

    iFilledRectangle(pipe_lower_3-=speed,pipe_upper_3=pipe_lower_height_3+distance_between_pipes, dx,pipe_upper_height_3=console_y-pipe_upper_3);

    iFilledRectangle(pipe_lower_4-=speed,pipe_upper_4=pipe_lower_height_4+distance_between_pipes, dx,pipe_upper_height_4=console_y-pipe_upper_4);

    iFilledRectangle(pipe_lower_5-=speed,pipe_upper_5=pipe_lower_height_5+distance_between_pipes, dx,pipe_upper_height_5=console_y-pipe_upper_5);

    iSetColor(black);
    sprintf(Score,"%d",score);
    iText(console_x*0.900,console_y*0.900,Score,GLUT_BITMAP_TIMES_ROMAN_24);

}
//End Function-IntoGame

//blinker that has been used during taking name of the player
int cursor_blinker=1;
void blinker(void)
{
    cursor_blinker++;
}


//flag=0  Main Screen
//flag=1 Main Game/ play again
//flag=2 name input
//flag=3 GAME OVER
//flag=4 quit.
//flag_score=2; for saving the scores in a file
//flag=5 name input;
//cursor_blinker=1;


char str[]="wall.bmp";

void changeBackground()
{
    if(!strcmp(str,"wall.bmp"))
    {
        strcpy(str,"wall(name).bmp");
    }
    else
    {
        strcpy(str,"wall.bmp");
    }

}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int playSound()
{
    PlaySound("Smashing-Yuri_Santana-1233262689.wav", NULL, SND_ASYNC);
    delay(1000);
    return 0;
}




void iDraw()
{
    if(flag==5)
    {
        iClear();
        high_score();
    }
    if(flag==-1)
    {
        iClear();
        iShowBMP(console_x/2-375,console_y/2-350,str);
        iSetColor(sky);
        iText(console_x*intro_x,console_y*intro_y,"PRESS ENTER!!",GLUT_BITMAP_TIMES_ROMAN_24);

    }
    //game over conditions and scoring

    if(flag==1)
    {

        if(y-r==0)
        {
            playSound();
            flag=2;
        }

        if((pipe_lower_1)==(x+r) )
        {
            score++;
        }
        if(x+r>=pipe_lower_1 && (x-r)<=pipe_lower_1+dx && (y-r)<=pipe_lower_height_1 )
        {
            playSound();
            flag=2;

        }

        if((pipe_lower_2)==(x+r) )
        {
            score++;
        }
        if(x+r>=pipe_lower_2 && (x-r)<=pipe_lower_2+dx && (y-r)<=pipe_lower_height_2 )
        {
            playSound();
            flag=2;

        }
        if((pipe_lower_3)==(x+r) )
        {
            score++;
        }
        if(x+r>=pipe_lower_3 && (x-r)<=pipe_lower_3+dx && (y-r)<=pipe_lower_height_3 )
        {
            playSound();
            flag=2;

        }
        if((pipe_lower_4)==(x+r) )
        {
            score++;
        }
        if(x+r>=pipe_lower_4 && (x-r)<=pipe_lower_4+dx && (y-r)<=pipe_lower_height_4 )
        {
            playSound();
            flag=2;

        }
        if((pipe_lower_5)==(x+r) )
        {
            score++;
        }
        if(x+r>=pipe_lower_5 && (x-r)<=pipe_lower_5+dx && (y-r)<=pipe_lower_height_5 )
        {
            playSound();
            flag=2;

        }
        if(x+r>=pipe_lower_1 && (x-r)<=pipe_lower_1+dx && (y+r)>=pipe_upper_1 )
        {
            playSound();
            flag=2;

        }
        if(x+r>=pipe_lower_2 && (x-r)<=pipe_lower_2+dx && (y+r)>=pipe_upper_2 )
        {
            playSound();
            flag=2;
        }
        if(x+r>=pipe_lower_3 && (x-r)<=pipe_lower_3+dx && (y+r)>=pipe_upper_3 )
        {
            playSound();
            flag=2;

        }
        if(x+r>=pipe_lower_4 && (x-r)<=pipe_lower_4+dx && (y+r)>=pipe_upper_4 )
        {
            playSound();
            flag=2;

        }
        if(x+r>=pipe_lower_5 && (x-r)<=pipe_lower_5+dx && (y+r)>=pipe_upper_5 )
        {
            playSound();
            flag=2;
        }

    }
    if(flag==0)     //Main Menu
    {
        main_menu();

    }

    if(flag==1)     //Into To The Game
    {
        intoGame();
    }

    if(flag==2) //asking for players name
    {
        iClear();
        iSetColor(red);
        iFilledRectangle(0,0,console_x,console_y);
        iSetColor(white);

        iText(console_x*GAMEOVER_F2_X,console_y*GAMEOVER_F2_Y,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(console_x*name_takerx,console_y*name_takery,"Enter your name in lower case alphabets:(highest 10 characters):",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(console_x*ch_f2_X,console_y*ch_f2_Y,temp,GLUT_BITMAP_TIMES_ROMAN_24);

        iRectangle(console_x*0.240,console_y*0.475,console_x*0.175,console_y*0.070);

        //the cursor
        if(cursor_blinker%2==0)
        {
            iSetColor(white);
        }
        else
            iSetColor(red);

        iLine(cursor_xs,cursor_ys,cursor_xe,cursor_ye);


        if(t==10)
            flag=3;
    }

    if(flag==3)//GAME OVER
    {
        iClear();
        iSetColor(red);
        iFilledRectangle(0,0,console_x,console_y);
        iSetColor(white);
        sprintf(Score,"%d",score);

        strcpy(name,temp);
        iText(console_x*Name_x,console_y*Name_y,temp,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(console_x*score_x,console_y*score_y,Score,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(console_x*gameover_x,console_y*gameover_y,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(console_x*SCORE_X,console_y*SCORE_Y,"SCORE: ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(console_x*play_again_button_x,console_y*play_again_button_y,"Play Again",GLUT_BITMAP_TIMES_ROMAN_24);

        if(flag_score==2)
        {
            score_records();
            flag_score=-1;
        }

        //quit button
        iSetColor(white);
        drawTexture(q_g_x,q_g_y,quittexture);

    }

    //when the quit button is clicked the flag will be assigned 4 and exit the game.
    if(flag==4)
    {
        exit(1);
    }


}

void iMouseMove(int mx, int my)
{
    printf("x = %d, y= %d\n",mx,my);
}

void iMouse(int button, int state, int mx, int my)//Clicking action condition
{
    //the ball moving upwards
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (flag==1))
    {
        y += ball_up;
    }

    //click the play button and start playing
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (flag==0))
    {
        if((mx>=console_x*0.01 && mx<=console_x*0.01+500) && (my>=console_y*0.75 && my<=console_y*0.75+250))
            flag=1;
        if((mx>=console_x*0.01 && mx<=console_x*0.01+500) && (my>=console_y*0.55 && my<=console_y*0.55+250))//HIGH SCORE
            flag=5;
        if((mx>=console_x*0.01 && mx<=console_x*0.01+500) && (my>=console_y*0.35 && my<=console_y*0.35+250))//QUIT
            flag=4;
    }

    //play again
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (flag==3) &&(mx>=console_x*0.1 && mx<=console_x*3) && (my>=console_y*0.4 && my<=console_y*0.5))
    {
        iClear();
        reset_values();
        flag=1;
    }

    //quit
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (flag==3) &&(mx>=console_x*0.3 && mx<=console_x*4) && (my>=console_y*0.50 && my<=console_y*0.65))
    {
        flag=4;
    }



}

void iKeyboard(unsigned char key)
{
    //the Esc button will bring the user back to the main menu
    if(key==27 && flag==5)
    {
        flag=0;
    }

    if(flag==-1 && key=='\r')
    {
        flag=0;
    }
    if(key=='W')
    {
        y+=ball_up;
    }

//taking names;
    if(flag==2)
    {
        switch(key)
        {
        case 'a':
            temp[t]='a';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'b':
            temp[t]='b';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'c':
            temp[t]='c';
            t++;
            break;

        case 'd':
            temp[t]='d';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'e':
            temp[t]='e';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'f':
            temp[t]='f';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'g':
            temp[t]='g';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'h':
            temp[t]='h';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'i':
            temp[t]='i';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'j':
            temp[t]='j';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'k':
            temp[t]='k';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'l':
            temp[t]='l';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'm':
            temp[t]='m';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'n':
            temp[t]='n';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'o':
            temp[t]='o';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'p':
            temp[t]='p';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'q':
            temp[t]='q';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'r':
            temp[t]='r';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 's':
            temp[t]='s';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 't':
            temp[t]='t';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'u':
            temp[t]='u';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'v':
            temp[t]='v';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'w':
            temp[t]='w';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'x':
            temp[t]='x';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'y':
            temp[t]='y';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case 'z':
            temp[t]='z';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        case ' ':
            temp[t]=' ';
            t++;
            cursor_xs+=bp;
            cursor_xe+=bp;
            break;

        }
    }

    if(flag==2 && key==13)
    {
        flag=3;
    }

    if(flag==2 && key==8)
    {
        t--;
        temp[t]=temp[t+1];
        cursor_xs-=bp;
        cursor_xe-=bp;
    }

}

void iSpecialKeyboard(unsigned char key)
{
    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
}

int main()
{
    srand(time(NULL));
    iSetTimer(1000,blinker);
    iSetTimer(1000,timeblinker);
    iSetTimer(750,changeBackground);
    iInitialize(console_x, console_y, "Flappy Ball");
    return 0;
}
