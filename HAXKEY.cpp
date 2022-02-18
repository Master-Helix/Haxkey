#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;


void init_code(){
    fast();
}


string hash_code_creation(string Username,string Password)
{
   int s1=Username.size(),s2=Password.size();

   string key="";

   if(s1%2==0 && s2%2==0)
   {
      key+='@';
   }
   else if(s1%2!=0 && s2%2==0)
   {
      key+='#';
   }
   else if(s1%2==0 && s2%2!=0)
   {
      key+='$';
   }
   else
   {
      key+='%';
   }
   string a1=to_string(s1);
   string a2=to_string(s2);
   key+=a1+a2;
   string check="";
   check+=Username+Password;
   for(int i=0;i<check.length();i++)
   {
      if(i%2==0)
      {
         key+=check[i];
      }
   }

   return key;
}

string cipheration(string First_name)
{
   for(int i=0;i<First_name.size();i++)
   {
      First_name[i]=First_name[i]+(First_name.size()%4);
   }
   return First_name;
}

string decipheration(string First_name)
{
   for(int i=0;i<First_name.size();i++)
   {
      First_name[i]=First_name[i]-(First_name.size()%4);
   }
   return First_name;
}


int SignUp(map<string,vector<string> >&store,string code,string Username,string Password)
{
   if(store.find(code)!=store.end())
   {
      cout<<"User with same hash code already exists! Try different Username/Password !"<<endl;
      return 0;
   }
   else
   {
      cout<<"Account created Successfully !"<<endl;
      return 1;
   }

}

int Login(map<string,vector<string>>&store,string code)
{
   if(store.find(code)!=store.end())
      {
         cout<<"You have logged In Successfully!"<<endl;
         return 1;
      }
      else
      {
         cout<<"First sign up in the system!"<<endl;
         return 0;
      }
}


 // Code made by RAKSHIT PANDEY
int main() {
   init_code();

    
   map<string,vector<string>>store;
   int Login_token=0,SignUp_token=0;
   string First_name,Last_name,Username,Password;
   string code;


   while(1){
      cout<<"Hello! Welcome to the HAXKEY! Press 1 to Sign up and 2 to Login and 0 to exit "<<endl;
      int choice;
      cin>>choice;
      if(choice==1)
      {
         cout<<"Enter the Sign Up Credentials :-"<<endl;
         cout<<"Enter the First_name : "<<endl;
         cin>>First_name;
         cout<<"Enter the Last_name : "<<endl;
         cin>>Last_name;
         cout<<"Enter the Username : "<<endl;
         cin>>Username;
         cout<<"Enter the Password : "<<endl;
         cin>>Password;

         code=hash_code_creation(Username,Password);
         int flag1=SignUp(store,code,Username,Password);
         if(flag1==1)
         {
            SignUp_token=1;
            vector<string>v;
            cout<<"We will store the credentials in ciphered form"<<endl;
            First_name=cipheration(First_name);
            v.push_back(First_name);
            Last_name=cipheration(Last_name);
            v.push_back(Last_name);
            Username=cipheration(Username);
            v.push_back(Username);
            Password=cipheration(Password);
            v.push_back(Password);
            store[code]=v;
         }
      }

      else if(choice==2)
      {
          cout<<"Enter the Login Credentials :-"<<endl;
          cout<<"Enter the Username : "<<endl;
          cin>>Username;
          cout<<"Enter the Password : "<<endl;
          cin>>Password;
          code=hash_code_creation(Username,Password);
          int flag2=Login(store,code);
          if(flag2==1)
          {
            Login_token=1;
          }
      }
      else if(choice!=1 && choice!=2 && choice!=0)
      {
         cout<<"You entered wrong option! Input again."<<endl;
      }
      else if(choice==0)
      {
         cout<<"Moving Ahead!"<<endl;
         break;
      }
   }

  if(Login_token==1){

   while(1)
   {
       string option1;
      cout<<"Do you want to see your Hash Code ?Enter yes or no!"<<endl;
      cin>>option1;
      if(option1=="no")
      {
         cout<<"Your hash code is not shown!"<<endl;
         break;
      }

      else if(option1=="yes")
      {
         cout<<"Enter the Username and Password whose hash code you want? "<<endl;
         cout<<"Enter the Username : "<<endl;
         string u1,p1;
         cin>>u1;
         cout<<"Enter the Password : "<<endl;
         cin>>p1;

         string code1=hash_code_creation(u1,p1);
         if(store.find(code1)==store.end())
         {
            cout<<"User is  not registered in the system!"<<endl;
         }
         else
         {
            cout<<"The specfied Hash Code is :- "<<code1<<endl;
         }
         break;
      }
      else
      {
         cout<<"Enter Either yes or no..!"<<endl;
      }
   }





   while(1)
   {
         string option2;
      cout<<"Do you want to display the original data (in Deciphered Form)? Enter yes or no!"<<endl;
      cin>>option2;
      if(option2=="no")
      {
         cout<<"Thank You for using our Services. BYE! "<<endl;
         break;
      }
      else if(option2=="yes")
      {
         cout<<"Enter your Hash Code : "<<endl;
         string code2;
         cin>>code2;
         vector<string>output;
         if(store.find(code2)==store.end())
         {
            cout<<"Your Profile has not been registered in the system!"<<endl;
         }
         else
         {
            for(auto it=store.begin();it!=store.end();it++)
            {
               if(it->first==code2)
               {
                  output=it->second;
                  break;
               }
            }

            cout<<"Your Actual First Name is : "<<decipheration(output[0])<<endl;
            cout<<"Your Actual Last Name is : "<<decipheration(output[1])<<endl;
            cout<<"Your Actual Username is : "<<decipheration(output[2])<<endl;
            cout<<"Your Actual Password is : "<<decipheration(output[3])<<endl;
            break;
         }
      }
      else
      {
         cout<<"Enter Either yes or no..!"<<endl;
      }
   }



   while(1)
   {
        string option3;
      cout<<"Do you want to display the whole stored table with all contents ? Enter yes or no!"<<endl;
      cin>>option3;
      if(option3=="no")
      {
         cout<<"Thank You for using our Services . Have a Good Day !"<<endl;
         break;
      }
      else if(option3=="yes")
      {
         int ctr=1;
         for(auto it=store.begin();it!=store.end();it++)
         {
            cout<<"Details of User :- "<<ctr<<" : "<<endl;
            cout<<"The Corresponding Hash Code is : "<<it->first<<endl;
            cout<<"Converted First Name is : "<<it->second[0]<<endl;
            cout<<"converted Last Name is : "<<it->second[1]<<endl;
            cout<<"Converted Username is : "<<it->second[2]<<endl;
            cout<<"Converted Password is : "<<it->second[3]<<endl;
            cout<<"<-------------------------------------->"<<endl;
            ctr++;
         }
         break;
      }
      else
      {
         cout<<"Enter Either yes or no..!"<<endl;
      }
   }

  }
   
   else{

   cout<<"THANK YOU For using The HAXKEY Services !! Have a Nice Day:)"<<endl;
   }
   return 0;

}
