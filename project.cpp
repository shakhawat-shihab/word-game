#include<bits/stdc++.h>
#include<graphics.h>
#include<iostream>
#include<MMSystem.h>
#include <cstdlib>
using namespace std;
int siz;
int maxx,maxy;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
int flag=0,light=0;
int arrowFound;
int maxLengthOfWord(string arr[], int row)
{
    int max_width_of_letter=0;
    int rows=row;
    for(int i=0; i<rows; i++)
    {
        string st=arr[i];
        if(st.length()>=max_width_of_letter)
        {
            max_width_of_letter=st.length();
        }
    }
    return max_width_of_letter;
}
void hints()
{
    int y=maxy-130;
    int x=0,
        setcolor(WHITE);
    line(x,y,maxx,y);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(x+50,y+20,"Click Arrow to select Box");
    outtextxy(x+50,y+50,"Insert Letter in the selected Box");
    outtextxy(x+50,y+80,"Click Enter to Submit the Answer");
}
void homePage()
{
    setcolor(RED);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 5);
    outtextxy(maxx/2-100,80,"Word Game");
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(100,maxy/2-100,"Enter 1 for Easy Game");
    outtextxy(100,maxy/2-30,"Enter 2 for Medium Game");
    outtextxy(100,maxy/2+40,"Enter 3 for Hard Game");
}

void  showSquarePointer(int  x1,int y1,int color)
{
    setcolor(color);
    line(x1,y1,x1+siz,y1);
    line(x1,y1,x1,y1+siz);
    line(x1,y1+siz,x1+siz,y1+siz);
    line(x1+siz,y1+siz,x1+siz,y1);

}
string editData(string ar[],int row)
{
    string arr[row];
    copy(ar, ar + row, arr);
    map<pair<int, int>, char > m;
    //size_t rows = sizeof(arr);
    int rows=row;
    cout<<" edit rows "<<rows<<endl;
    int max_width_of_letter=0;
    for(int i=0; i<rows; i++)
    {
        string st=arr[i];
        if(st.length()>=max_width_of_letter)
        {
            max_width_of_letter=st.length();
        }
    }
    //char answer[rows][max_width_of_letter]= {{0}};
    int width=max_width_of_letter*siz;
    int space=maxx-width;
    int leftSpace=space/2.5;
    leftSpace= leftSpace+(maxx-leftSpace)/2;
    int p=siz,q=siz+siz;
    //int currentPointer[2]=[leftSpace,p];
    int x1=leftSpace;
    int y1=siz*2;
    showSquarePointer(x1,y1,4);
    int pos_row=0,pos_col=0;
    int c, ex;
    while(1)
    {
        if(flag==0)
        {
            c = getch();
        }
        else
        {
            cout<<"arrowFound jjjjj:"<<arrowFound<<endl;;
            c=arrowFound;
        }
        switch(c)
        {
        case KEY_UP:
        {
            cout << c << "Up" << endl;//key up
            if(y1>siz*2)
            {
                //before moving pointer make current pointer white
                showSquarePointer(x1,y1,7);
                y1=y1-siz;
                showSquarePointer(x1,y1,4);
                pos_row--;
                PlaySound(TEXT("audio/key_vertical.wav"),NULL,SND_SYNC);
            }
            flag=0;
            break;
        }
        case KEY_DOWN:
        {
            cout << c << "Down" << endl;//key down
            if(y1<rows*siz+siz)
            {
                //before moving pointer make current pointer white
                showSquarePointer(x1,y1,7);
                y1=y1+siz;
                showSquarePointer(x1,y1,4);
                pos_row++;
                PlaySound(TEXT("audio/key_vertical.wav"),NULL,SND_SYNC);
            }
            flag=0;
            break;
        }
        case KEY_RIGHT:
        {
            cout << c << "Right" << endl;//key right
            if(x1<(leftSpace+width-siz))
            {
                //before moving pointer make current pointer white
                showSquarePointer(x1,y1,7);
                x1=x1+siz;
                showSquarePointer(x1,y1,4);
                pos_col++;
                PlaySound(TEXT("audio/key_horizontal.wav"),NULL,SND_SYNC);
            }
            flag=0;
            break;
        }
        case KEY_LEFT:
        {
            cout << c << "Left" << endl;//key right
            if(x1>leftSpace)
            {
                //before moving pointer make current pointer white
                showSquarePointer(x1,y1,7);
                x1=x1-siz;
                showSquarePointer(x1,y1,4);
                pos_col--;
                PlaySound(TEXT("audio/key_horizontal.wav"),NULL,SND_SYNC);
            }
            flag=0;
            break;
        }
        case 13:
        {
            cout<<"Enter key is pressed"<<endl;
            PlaySound(TEXT("audio/enter_button.wav"),NULL,SND_SYNC);
            for(auto it = m.begin(); it != m.end(); ++it)
            {
                cout << it->first.first << " " << it->first.second << " " << it->second << "\n";
                arr[it->first.first][it->first.second]=it->second;
            }
            string answer="";
            for(int i=0; i<rows; i++)
            {
                cout<<"fun == "<<arr[i]<<"\n";
                answer+=arr[i];
            }
            flag=0;
            return answer;
            break;
        }
        default:
            cout<<"nothing satisfied : "<<c<<endl;
        }
        cout<<"Current Data :"<<arr[pos_row][pos_col]<<endl;

        if(arr[pos_row][pos_col]=='$')
        {
            while(1)
            {
                int letter;
                letter=getch();
                light=1;
                if(letter==KEY_UP||letter==KEY_DOWN||letter==KEY_RIGHT||letter==KEY_LEFT||letter==13)
                {
                    cout<<"KEY"<<endl;
                    arrowFound=letter;
                    flag=1;
                    break;
                }
                if(letter>='a'&&letter<='z')
                {
                    cout<<"letter : "<<letter<<endl;
                    char text[2] = { letter, 0 };
                    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
                    outtextxy(x1+siz/2-8,y1+siz/2-8,text);
                    //m[pos_row][pos_col] = letter;
                    auto itr = m.find(make_pair(pos_row,pos_col));
                    if (itr != m.end())
                    {
                        cout<<"updating "<<endl;
                        m.erase(itr);
                        m.insert( make_pair(make_pair(pos_row, pos_col), char(letter)) );
                    }
                    else
                    {
                        cout<<"just inserting"<<endl;
                        m.insert( make_pair(make_pair(pos_row, pos_col), char(letter)) );
                    }
                }
                if(letter>='A'&&letter<='Z')
                {
                    cout<<"Special case "<< letter<<endl;
                }
                cout<<"[pos_row] & [pos_col] = "<< pos_row << " & "<< pos_col<<endl;
            }
        }
        //getch()
    }
}

void showData(string arr[],int row)
{
    //size_t rows = sizeof(arr);
    //cleardevice();
    int rows=row;
    int max_width_of_letter=maxLengthOfWord(arr,row);
    cout<< "siz "<<siz<<endl;
    int width=max_width_of_letter*siz;
    int space=maxx-width;
    int leftSpace=space/2.5;
    leftSpace= leftSpace+(maxx-leftSpace)/2;

    int p=siz*2,q=p+siz;

    setcolor(BLUE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(leftSpace+60,siz,"Playground");

    setcolor(WHITE);
    int showHintsNumbers=0;
    // draw dividing line

    line(leftSpace-50,0,leftSpace-50,maxy-130);
    for(int i=0; i<rows; i++)
    {
        string temp=arr[i];
        int x1=leftSpace,x2=leftSpace+siz;
        for(int j=0; j<temp.length(); j++)
        {
            line(x1,p,x2,p);
            line(x1,p,x1,q);
            line(x1,q,x2,q);
            line(x2,p,x2,q);
            //The third parameter of the outtextxy function
            // must be a pointer to a nul-terminated character string (or char array),
            if(temp[j]!='$')
            {
                char text[2] = { temp[j], 0 };
                settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
                outtextxy((x1+x2)/2-8,(p+q)/2-8,text);

                /*check if the text is underscore*/
                if(temp[j]=='_')
                {
                    setfillstyle (HATCH_FILL, YELLOW);
                    floodfill(x1+1, p+1, WHITE);
                }
            }
            else
            {
                showHintsNumbers++;
                string s=to_string(showHintsNumbers);
                int n = s.length();
                char char_array[n + 1];
                strcpy(char_array, s.c_str());
                settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
                outtextxy(x2-15,p+8,char_array);
            }
            x1=x1+siz;
            x2=x2+siz;
        }
        p=p+siz;
        q=q+siz;
    }
    cout<<"inside sow data "<<endl;
}

void showDataAfterSubmit(string arr[],string result[],string ans[],int row)
{
    //size_t rows = sizeof(arr);
    //cleardevice();
    int rows=row;
    int max_width_of_letter=maxLengthOfWord(arr,row);
    cout<< "siz "<<siz<<endl;
    int width=max_width_of_letter*siz;
    int space=maxx-width;
    int leftSpace=space/2.5;
    leftSpace= leftSpace+(maxx-leftSpace)/2;

    int p=siz*2,q=p+siz;

    setcolor(BLUE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(leftSpace+60,siz,"Playground");

    setcolor(WHITE);
    int showHintsNumbers=0;
    // draw dividing line

    line(leftSpace-50,0,leftSpace-50,maxy-130);
    for(int i=0; i<rows; i++)
    {
        string temp=arr[i];
        int x1=leftSpace,x2=leftSpace+siz;
        for(int j=0; j<temp.length(); j++)
        {
            line(x1,p,x2,p);
            line(x1,p,x1,q);
            line(x1,q,x2,q);
            line(x2,p,x2,q);
            //The third parameter of the outtextxy function
            // must be a pointer to a nul-terminated character string (or char array),
            if(temp[j]!='$')
            {
                char text[2] = { temp[j], 0 };
                settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
                outtextxy((x1+x2)/2-8,(p+q)/2-8,text);

                /*check if the text is underscore*/
                if(temp[j]=='_')
                {
                    setfillstyle (HATCH_FILL, YELLOW);
                    floodfill(x1+1, p+1, WHITE);
                }
            }
            else
            {
                showHintsNumbers++;
                string s=to_string(showHintsNumbers);
                int n = s.length();
                char char_array[n + 1];
                strcpy(char_array, s.c_str());
                settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
                outtextxy(x2-15,p+8,char_array);

                //ekane amr letter dekhabo
                if(ans[i][j]==result[i][j])
                {
                    setfillstyle(SOLID_FILL,GREEN);
                    circle(x2-12,q-12,7);
                    floodfill(x2-12,q-12,WHITE);
                    int letter=ans[i][j];
                    char text[2] = { letter, 0 };
                    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
                    outtextxy(x1+siz/2-8,p+siz/2-8,text);
                    setcolor(WHITE);
                }
                else
                {
                    setfillstyle(SOLID_FILL,RED);
                    circle(x2-12,q-12,7);
                    floodfill(x2-12,q-12,WHITE);
                    if(ans[i][j]!='$')
                    {
                        if(ans[i][j]!='$')
                        {
                            int letter=ans[i][j];
                            char text[2] = { letter, 0 };
                            settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
                            outtextxy(x1+siz/2-8,p+siz/2-8,text);
                        }
                    }
                    setcolor(WHITE);
                }

            }
            x1=x1+siz;
            x2=x2+siz;
        }
        p=p+siz;
        q=q+siz;
    }
    cout<<"inside sow data "<<endl;
}
//
//
//string* answer1Dto2D(string answer,int rows,int max_length_of_word)
//{
//    string ans[rows];
//    for(int i=0,row=0,col=0; i<answer.length(); i++)
//    {
//        char letter=answer[i];
//        if(i!=0 && i%max_length_of_word==0)
//        {
//            row++;
//            col=0;
//        }
//        ans[row][col]=letter;
//        col++;
//    }
//}
float *checkAnswer(string problem[],string result[],string answer,int rows)
{
    cleardevice();
    int max_length_of_word=maxLengthOfWord(problem,rows);
    string ans[rows];
    for(int i=0,row=0,col=0; i<answer.length(); i++)
    {
        char letter=answer[i];
        if(i!=0 && i%max_length_of_word==0)
        {
            row++;
            col=0;
        }
        ans[row]+=letter;
        col++;
    }
//    string *ans;
//    ans=answer1Dto2D(answer,rows,max_length_of_word);

    float *q = new float[3];
    int emptySpace=0;
    int correctAnswer=0;
    float accuracy;
    for (int i=0; i<rows; i++)
    {
        for(int j=0; j<max_length_of_word; j++)
        {
            cout<<"answer[i] [j] : "<<ans[i][j]<< " & result[i][j] "<<result[i][j]<<endl;
            if(problem[i][j]=='$')
            {
                emptySpace++;
                if(result[i][j]==ans[i][j])
                {
                    correctAnswer++;
                }
            }
        }
    }


    accuracy=(float(correctAnswer)/emptySpace)*100.0;
    //cout<<"correctAnswer "<< correctAnswer<< " emptySpace "<<emptySpace<<endl;
    //cout<<"accuracy fun:" << accuracy<<endl;
    q[0]=emptySpace;
    q[1]=correctAnswer;
    q[2]=accuracy;
    return q;
}

void showResult(float answerResult[])
{
    setcolor(BLUE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(250,50,"Result");
    //cout<<"Itsghcschgdvhsb "<< answerResult[0] <<endl;
    setcolor(WHITE);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR,4 );
    string s="You Made  "+to_string(int(answerResult[1]))+ "  answer correct out of  "+ to_string(int(answerResult[0])) ;
    int n = s.length();
    char char_array[n + 1];
    strcpy(char_array, s.c_str());
    outtextxy(60,170,char_array);
    if(answerResult[2]>=80)
    {
        setcolor(GREEN);
    }
    else if(answerResult[2]>=50)
    {
        setcolor(BLUE);
    }
    else
    {
        setcolor(RED);
    }
    string s1="Your accuracy is "+to_string(int(answerResult[2]))+" %";
    int n1 = s1.length();
    char char_array1[n1 + 1];
    strcpy(char_array1, s1.c_str());
    outtextxy(60,230,char_array1 );


    int y=maxy-130;
    setcolor(WHITE);
    line(0,y,maxx,y);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, WHITE);
    outtextxy(70,y+20,"Click Back Space to go Home Page");
}
bool playAgain()
{
    int key= 0;
    while(key!=8)
    {
        key=getch();
    }
    return true;
}
void showHints(string hints[],int n)
{
    setcolor(BLUE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(100,50,"Hints of the Playground");
    setcolor(WHITE);
    int x=50,y=120;
    for(int i=0; i<n; i++)
    {
        string s1=hints[i];
        int n1 = s1.length();
        char char_array1[n1 + 1];
        strcpy(char_array1, s1.c_str());
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(x,y,char_array1);
        y+=40;
    }
}
main()
{
    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, "");
    initwindow(1350,700);
    maxx=getmaxx();
    maxy=getmaxy();
    int y=0;
    homePage();
    while(1)
    {
        char mode=getch();
        cout<<"mode"<<mode<<endl;
        if(mode=='1')
        {
            cout<<"inside easy mode"<<endl;
            siz=65;
            cleardevice();
            string problem1[4]= { "se$d","$__$","o$ly","pe$_"};
            string problem2[4] = { "lea$n", "_p$or", "___am", "goo$_" };
            string result1[4]= { "send","t__a","oily","pen_" };
            string result2[4] = { "learn","_poor", "___am", "good_" };
            string problem1Hints[5] = {"1. Across -> Transfer Something","2. Down -> Halt of Movement","3. Down -> Time Between Sunrise and Sunset","4. Across -> Covered With Oil","5. Across -> Seed of a Pea Plant"};
            string problem2Hints[4] = {"1. Across -> Gain Knowledge","2. Across -> People Without Wealth","3. Across -> Morally Right","1+3. Down -> Walking place"};
            srand(time(NULL));
            int random=rand()%2;
            cout<<rand()<<" "<<random<<endl;
            float *answerResult;
            if(random==0)
            {
                showHints(problem1Hints,5);
                showData(problem1,4);
                hints();
                string answer=editData(problem1,4);
                answerResult= checkAnswer(problem1,result1,answer,4);
                cout<<"accuracy :" << answerResult[2]<<endl;

                int max_length_of_word=maxLengthOfWord(problem1,4);
                string ans[4];
                for(int i=0,row=0,col=0; i<answer.length(); i++)
                {
                    char letter=answer[i];
                    if(i!=0 && i%max_length_of_word==0)
                    {
                        row++;
                        col=0;
                    }
                    ans[row]+=letter;
                    col++;
                }
                showDataAfterSubmit(problem1,result1,ans,4);
                showResult(answerResult);
            }
            else if(random==1)
            {
                showHints(problem2Hints,4);
                showData(problem2,4);
                hints();
                string answer=editData(problem2,4);
                answerResult= checkAnswer(problem2,result2,answer,4);
                cout<<"accuracy :" << answerResult[2]<<endl;

                int max_length_of_word=maxLengthOfWord(problem2,4);
                string ans[4];
                for(int i=0,row=0,col=0; i<answer.length(); i++)
                {
                    char letter=answer[i];
                    if(i!=0 && i%max_length_of_word==0)
                    {
                        row++;
                        col=0;
                    }
                    ans[row]+=letter;
                    col++;
                }
                cout<< "ans "<<ans[0]<<endl;
                cout<<"problem "<<problem2[0]<<endl;
                showDataAfterSubmit(problem2,result2, ans,4);
                showResult(answerResult);
            }
            bool isPlayAgain=playAgain();
            if(isPlayAgain==true)
            {
                cleardevice();
                homePage();
            }
        }
        else if(mode=='2')
        {
            cout<<"inside medium mode"<<endl;
            siz=55;
            cleardevice();
            string problem1[7]= {"h$bit","at$m_","$to$d","vikg$","ec_eo","s___r","t$in_"};
            string problem2[7]= {"l$arn","a_t$a","be$_$","$y_ba","r$b$l","__$a_","do$r_"};
            string problem3[7]= {"nu$ber","$_be$n","e_a$ro","d$mon_","_c$r__","_on$__","____$e"};
            string result1[7]= {"habit","atom_","rtoad","vikgo","ec_eo","s___r","twin_"};
            string result2[7]= {"learn","a_tea","bee_v","ay_ba","rebel","__ia_","door_"};
            string result3[7]= {"number","e_bean","e_afro","demon_","_car_","_one_","___be"};
            string problem1Hints[6] = {"1. Across -> A Regular Practice", "2. Across -> The Smallest Particle of An Element", "3. Down ! The Process of Gathering Crops", "4. Down ! General Impression of A Person", "5. Down ! A Barrier to An Entrance", "6. Across -> Two Identical Person" };
            string problem2Hints[9] = {"1. Across -> Gain Knowledge","2. Across -> Refreshing Drink","3. Across -> Small Social Insect","4. Down ! Relating to Navy","5. Down ! Physical Hard Work","6. Down ! Organs of Sight", "7. Down ! Tolerate Something", "8. Down ! Living Organism", "9. Across -> A Barrier to An Entrance"};
            string problem3Hints[8] = {"1. Across -> A Quantity or Amount", "2. Down ! Necessity of Something", "3. Across -> Edible Seed of A Plant", "4. Down ! Earlier in Time","5. Across -> An Evil Supernatural Being","6. Across -> A Motor Vehicle", "7. Across -> A Single Amount", "8. Across -> Having An Existence"};
            srand(time(NULL));
            int random=rand()%3;
            cout<<rand()<<" "<<random<<endl;
            float *answerResult;
            if(random==0)
            {
                showHints(problem1Hints,6);
                showData(problem1,7);
                hints();
                string answer=editData(problem1,7);
                answerResult= checkAnswer(problem1,result1,answer,7);
                cout<<"accuracy :" << answerResult[2]<<endl;

                int max_length_of_word=maxLengthOfWord(problem1,7);
                string ans[7];
                for(int i=0,row=0,col=0; i<answer.length(); i++)
                {
                    char letter=answer[i];
                    if(i!=0 && i%max_length_of_word==0)
                    {
                        row++;
                        col=0;
                    }
                    ans[row]+=letter;
                    col++;
                }
                showDataAfterSubmit(problem1,result1, ans,7);
                showResult(answerResult);
            }
            else if(random==1)
            {
                showHints(problem2Hints,9);
                showData(problem2,7);
                hints();
                string answer=editData(problem2,7);
                answerResult= checkAnswer(problem2,result2,answer,7);
                cout<<"accuracy :" << answerResult[2]<<endl;

                int max_length_of_word=maxLengthOfWord(problem2,7);
                string ans[7];
                for(int i=0,row=0,col=0; i<answer.length(); i++)
                {
                    char letter=answer[i];
                    if(i!=0 && i%max_length_of_word==0)
                    {
                        row++;
                        col=0;
                    }
                    ans[row]+=letter;
                    col++;
                }
                showDataAfterSubmit(problem2,result2, ans,7);
                showResult(answerResult);
            }
            else if(random==2)
            {
                showHints(problem3Hints,8);
                showData(problem3,7);
                hints();
                string answer=editData(problem3,7);
                answerResult= checkAnswer(problem3,result3,answer,7);
                cout<<"accuracy :" << answerResult[2]<<endl;

                int max_length_of_word=maxLengthOfWord(problem3,7);
                string ans[7];
                for(int i=0,row=0,col=0; i<answer.length(); i++)
                {
                    char letter=answer[i];
                    if(i!=0 && i%max_length_of_word==0)
                    {
                        row++;
                        col=0;
                    }
                    ans[row]+=letter;
                    col++;
                }
                showDataAfterSubmit(problem3,result3, ans,7);
                showResult(answerResult);
            }

            bool isPlayAgain=playAgain();
            if(isPlayAgain==true)
            {
                cleardevice();
                homePage();
            }
        }
        else if(mode=='3')
        {
            cout<<"inside hard mode"<<endl;
            siz=50;
            cleardevice();
            string problem1[8]= {"co$rect","_ba$l_h","c$bg$ai","ot$hv$n", "duitet$","e$t_nii","_r___on","cy$ling"};
            string problem2[8]= {"natu$al","e$am_$o","ice$er$","ge$r__o","hon$st_","bu$ler_","$__l$mb","ro$ate_"};
            string problem3[8]= {"hea$ing","oa$h_o_","$rt_j$b","e$ev$n_","lyn____","a_d_m$g","n___$sk","dec$de_"};
            string result1[8]= {"correct","_bail_h","cibgeai","otbhvcn", "duitetk","eat_nii","_r___on","cycling"};
            string result2[8]= {"natural","exam_io","iceberg","gear__o","honest_","butler_","o__lamb","rotate_"};
            string result3[8]= {"healing","oath_o_","mrt_job","eleven_","lyn____","axd_mug","n___ask","decade_"};

            string problem1Hints[9] = {"1. Across -> Free From Mistakes", "2. Down ! Correct As A Fact", "3. Down ! A Notice of Death", "4. Down ! One More Than Ten", "5. Down ! A Small Plant Eating Animal", "6. Down ! A State of Being Active", "7. Down ! Be Capable of Conscious Thought", "8. Across -> Consume Something for Energy", "9. Across -> The Act of Riding A Cycle" };
            string problem2Hints[11] = {"1. Across -> something from nature", "2. Across -> A Test of Knowledge", "3. Down ! Means of Breathing", "4. Across -> a large floating mass of ice", "5. Down ! An Identifying Symbol", "6. Across -> Equipment for Particular Purpose", "7. Across -> Without Pretensions", "8. Across -> Chief Male Servant of A House", "9. Down ! A Person Living Next Door", "10. Down ! Somewhere to Sit On", "11. Across -> Moving in A Circle"};
            string problem3Hints[9] = {"1. Across -> The Process of Being Healthy", "2. Across -> A Solemn Promise", "3. Down ! The Native Land", "4. Across -> A Task or Piece of Work", "5. Down ! Before The Expected Time", "6. Across -> One More Than Ten", "7. Across -> A Drinking Cup", "8. Down ! Angry About Something", "9. Across -> A Period of Ten Years"};
            srand(time(NULL));
            int random=rand()%3;
            cout<<rand()<<" "<<random<<endl;
            float *answerResult;
            if(random==0)
            {
                showHints(problem1Hints,9);
                showData(problem1,8);
                hints();
                string answer=editData(problem1,8);
                answerResult= checkAnswer(problem1,result1,answer,8);
                cout<<"accuracy :" << answerResult[2]<<endl;

                int max_length_of_word=maxLengthOfWord(problem1,8);
                string ans[8];
                for(int i=0,row=0,col=0; i<answer.length(); i++)
                {
                    char letter=answer[i];
                    if(i!=0 && i%max_length_of_word==0)
                    {
                        row++;
                        col=0;
                    }
                    ans[row]+=letter;
                    col++;
                }
                showDataAfterSubmit(problem1,result1, ans,8);
                showResult(answerResult);
            }
            else if(random==1)
            {
                showHints(problem2Hints,11);
                showData(problem2,8);
                hints();
                string answer=editData(problem2,8);
                answerResult= checkAnswer(problem2,result2,answer,8);
                cout<<"accuracy :" << answerResult[2]<<endl;

                int max_length_of_word=maxLengthOfWord(problem2,8);
                string ans[8];
                for(int i=0,row=0,col=0; i<answer.length(); i++)
                {
                    char letter=answer[i];
                    if(i!=0 && i%max_length_of_word==0)
                    {
                        row++;
                        col=0;
                    }
                    ans[row]+=letter;
                    col++;
                }
                showDataAfterSubmit(problem2,result2, ans,8);
                showResult(answerResult);
            }
            else if(random==2)
            {
                showHints(problem3Hints,9);
                showData(problem3,8);
                hints();
                string answer=editData(problem3,8);
                answerResult= checkAnswer(problem3,result3,answer,8);
                cout<<"accuracy :" << answerResult[2]<<endl;

                int max_length_of_word=maxLengthOfWord(problem3,8);
                string ans[8];
                for(int i=0,row=0,col=0; i<answer.length(); i++)
                {
                    char letter=answer[i];
                    if(i!=0 && i%max_length_of_word==0)
                    {
                        row++;
                        col=0;
                    }
                    ans[row]+=letter;
                    col++;
                }
                showDataAfterSubmit(problem3,result3, ans,8);
                showResult(answerResult);
            }
            bool isPlayAgain=playAgain();
            if(isPlayAgain==true)
            {
                cleardevice();
                homePage();
            }

        }
    }
    getch();
}
