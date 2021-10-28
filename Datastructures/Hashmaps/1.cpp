#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
    unordered_map<string,int> map;
    /*****Inserting a element
    ******/
    //1st method
    pair<string,int> p("samarth",1);
    map.insert(p);

    //2nd method
    map["babbar"]=2;
    /****accesing a element
    ***/

   //1st method
   cout<<map["samarth"]<<endl;

   //2nd method
   cout<<map.at("babbar")<<endl;

   /**difference in accesing using at and []**/

   //cout<<map.at("new")<<endl;  will throw an error

   cout<<map["new"]<<endl; //will give 0 as "new" was not present
                           //and also this will insert this pair

    //count function: to see if element is present
    if(map.count("samarth"))
    cout<<"samarth is present"<<endl;

    //size function
    cout<<"before erasing new "<<map.size()<<endl;

    //erase fucntion
    map.erase("new");

    cout<<"after erasing new "<<map.size()<<endl;
}