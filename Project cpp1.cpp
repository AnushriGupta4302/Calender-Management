#include<iostream>
#include<ctime>
#include<windows.h>

using namespace std;
void heading (char ch, int i) {
int j;
for(j=0;j<=i;j++)
    cout<<ch;
}
void start_up() {
char ch[30]="WELCOME TO MY PROJECT ! ! \n ";
cout<<"\t \t \t";
for (int i=0;i<30;i++) {
    Sleep(150);
    cout<<ch[i];
}
for(int i=0;i<=79;i++) {
    Sleep (30);
    cout<<"\xDB";
}
system("c ls");
}

class calender {
private:
    int date,month,year;
public:
    calender(int d=1,int m=1,int y=1700) {
    date=d;
    month=m;
    year=y;
    }
    void day(int);
    void monthcal(int,int);
    bool leapyear(int);
    int daysinmonth(int,int);
    int daynumber(int,int,int);
};

bool calender :: leapyear(int y) {
bool leap;
if((y%4==0) && ((y%100 != 0) || (y%400==0)))
    leap=true;
else
    leap=false;
return leap;
}

int calender:: daysinmonth(int m,int y) {
switch (m) {
case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12: return 31;
case 2: if(leapyear(y))
return 29;
    else
return 28;
default: return 30;
}
}

int calender :: daynumber(int d,int m,int y) {
int i;
int dow=6;
for(i=1583;i<y;i++) {
    dow+=364;
}
for(i=1;i<m;i++)
    dow+=daysinmonth(i,y);
dow+=d;
return dow;
}

void calender :: day(int a) {
switch (a) {
case 1:
    cout<<"MONDAY";
    break;
    case 2:
    cout<<"TUESDAY";
    break;
    case 3:
    cout<<"WEDNESDAY";
    break;
    case 4:
    cout<<"THURSDAY";
    break;
    case 5:
    cout<<"FRIDAY";
    break;
    case 6:
    cout<<"SATURDAY";
    break;
    case 0:
    cout<<"SUNDAY";
    break;
    default :
        cout<<"\a\a\a\n\n" ;
}
}

void calender :: monthcal(int month, int year) {

int j,mon,c;
j=0;
for(j=0;j<=6;j++) {
    day(j);
    cout<<" ";
}
j=1;
c=daynumber(--j,month,year);
c=c%7;
cout<<"\n";
switch(c) {
case 0:
    break;
case 1:
    cout<<"\t";
    break;
case 2:
    cout<<"\t \t";
    break;
case 3:
    cout<<"\t \t \t";
    break;
case 4:
    cout<<"\t \t \t \t";
    break;
case 5:
    cout<<"\t \t \t \t \t";
    break;
case 6:
    cout<<"\t \t \t \t \t \t";
}
mon=daysinmonth(month,year);
for(j=1;j<=mon;j++) {
    cout<<" "<<j<<"\t";
    c++;
    if(!(c%7))
        cout<<"\n";
}
}

int main() {
int x,y,z;
system("color 5f");
char ch;
char t='\xCD';
do {
    system("c ls");
    int i,date, month, year;
    heading(t,79);
    cout<<"\n  \t WELCOME TO MY PROJECT ! ! \n \t Calender of 700 years (1700-2400)\n ";
    heading(t,79);
    cout<<"\n Enter 1 for knowing the day of a specific date \n Enter 2 to view the calender of any given month\n Enter 3 to calculate your age\n";
    cin>>i;
    if(i==1) {
        cout<<"Enter date (DD) :";
        cin>>date;
        if(date>31 || date<1) {
            cout<<"\nProvide valid date.\t Press any key";
            return(0);
            system("c ls");
            main();
        }
        month:
            cout<<"Enter Month (MM) : ";
            cin>>month;
            if(month>12 || month<1) {
                cout<<"Provide valid month.\t Press any key";
                return(0);
                goto month;
            }
            year:
                cout<<"Enter Year (YYYY) :";
            cin>>year;
            if(year>2400 || year<1700) {
                cout<<"Provide valid year.\t Press any key";
                return(0);
                goto year;
    }
    calender obj(date,month,year);
    i=obj.daynumber(--date,month,year);
    cout<<"\n"<<++date<<" / "<<month<<" / "<<year<<" "<<"is ";
    i=i%7;
    obj.day(i);
}
else if(i==2) {
        cout<<"Enter month (MM) : ";
cin>>month;
month2:
    if(month>12 || month<1) {
        cout<<"Provide valid month.\t Press any key";
        return(0);
        goto month2;
    }
    cout<<"Enter year (YYYY) :";
    cin>>year;
    year2:
        if(year>2400 || year<1700) {
            cout<<"Provide valid year.\t Press any key";
            return(0);
            goto year2;
        }
        calender obj;
        obj.monthcal(month,year);
}
else if (i==3) {
    cout<<"Enter Date Of Birth:\n";
    cout<<"Date (DD) :";
    cin>>date;
    if (date>31 || date<1){
        cout<<"Provide valid date.\t Press any key";
        return(0);
        system("c ls");
        main();
    }
    month3:
        cout<<"Month (MM) :";
        cin>>month;
    if(month>12 || month<1) {
        cout<<"Provide valid month.\t Press any key";
        return(0);
        goto month3;
    }
    year3:
        cout<<"Enter year (YYYY) :";
    cin>>year;
        if(year>2014 || year<1900) {
            cout<<"Provide valid year.\t Press any key";
            return(0);
            goto year3;
        }
        long int p;
        calender dob(date,month,year);
        p=dob.daynumber(date,month,year);
        time_t t=time(0);
        struct tm*now=localtime(&t);
        date=now->tm_mday;
        month=(now->tm_mon+1);
        year=(now->tm_year+1900);
        long int q;
        calender cur(date,month,year);
        q=cur.daynumber(date,month,year);
        int my_y=(q-p)/365;
        int my_m=((q-p)%365)/30;
        int my_d=((q-p)%365)%30;
        cout<<"your age is "<< my_y <<" years "<< my_m <<" months and "<< my_d <<" days \n";
    }

}
    while (ch=='y' || ch=='Y');
    return 0;
}
