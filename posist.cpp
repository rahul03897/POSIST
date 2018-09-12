#include <bits/stdc++.h>
using namespace std;

void input(void);
class TimeStamp{

    public:

    string datetime;

    void put(string datetime1)
    {
        datetime=datetime1;
    }

    string getdatetime()
    {
        return datetime;
    }

};

struct Data{

 string name,address,mobile,phone,password,algo;
 float value;
};

struct node{

  TimeStamp Datetime;
  struct Data* data;
  unsigned int NodeNumber;
  unsigned int NodeId;
  struct node *ref;
  vector<struct node*> child;
};

map<int,struct node*> all;

static int number=0;
string datetime()
{
     time_t tt;
    struct tm * ti;
    time (&tt);
    ti = localtime(&tt);

    return asctime(ti);
}

unsigned int unique()
{
    return rand();
}

string encrypt(string value){
    char key ='H';
    string output = value;

    for (int i = 0; i < value.size(); i++)
        output[i] = value[i] ^ key;

    return output;
}

void input(int head,vector<struct node*> headnodes)
{

    int size = headnodes.size();
    string name,address,mobile,phone,password,algo="qwerty";
    float value;
    //cout<<"Enter your name:\n Enter your Address:\n  Enter your Mobile:\n  Enter your Phone:\n Enter Value :\n Enter password :"<<endl;

    //cin>>name>>address>>mobile>>phone>>value>>password;

    struct node *node1 = new node();
    struct Data *data1=new Data();
    string date = datetime();
    TimeStamp time;
    time.put(date);
    node1->Datetime=time;
    cout<<"Enter Name:\n";
    cin>>name;
    data1->name=encrypt(name);
    cout<<"Enter Address:\n";
    cin>>address;
    data1->address=encrypt(address);
    cout<<"Enter Mobile:\n";
    cin>>mobile;
    data1->mobile=encrypt(mobile);
    cout<<"Enter Phone:\n";
    cin>>phone;
    data1->phone=encrypt(phone);
    cout<<"Enter Password:\n";
    cin>>password;
    data1->password=encrypt(password);

    data1->algo=encrypt(algo);
    cout<<"Enter Value:\n";
    cin>>value;
    data1->value=value;

    node1->data=data1;
    node1->NodeNumber=++number;
    node1->NodeId=unique();


    if(head==-1)
    {
        node1->ref=NULL;
        headnodes.push_back(node1);
    }
    else
    {
        all[head]->child.push_back(node1);
        node1->ref=all[head];

    }

    all[number]=node1;
    return;
}

bool printverify(string password,string algo)
{
        string password1=encrypt(password);
        string algo1=encrypt("qwerty");

        map<int,struct node*>::iterator it=all.begin();
        int flag=0;

        for(;it!=all.end(); it++)
        {
            if(it->second->data->password==password1 && it->second->data->algo==algo1)
            {
                flag=1;

                cout<<encrypt(it->second->data->address)<<endl;
                cout<<encrypt(it->second->data->phone)<<endl;
                cout<<encrypt(it->second->data->mobile)<<endl;
                cout<<encrypt(it->second->data->name)<<endl;

                break;
            }
        }

        if(flag==1)
        return true;

        return false;
}

int c=0;

void longest(struct node* root,int &ma)
{
    	if(root==NULL)
            return;

 		   c++;

    		for(int i=0; i<root->child.size(); i++)
            {
                longest(root->child[i],ma);
            }

    	if(c>ma)
            ma=c;
}

void levels(struct node* root,int c,int &ma)
{
    	if(root==NULL)
            return;

    		for(int i=0; i<root->child.size(); i++)
            {
                levels(root->child[i],c+1,ma);
            }

    	if(c>ma)
            ma=c;
}

void merge(struct node* first,struct node * second,vector<struct node*> headnodes)
{

}

int main()
{
    vector<struct node *> headnodes;


    while(1)
    {
        cout<<"\n************************************************************\n";
cout<<"1 : Option to create first node\n";
    cout<<"2 : Option to create multi set of first node\n";
    cout<<"3 : Option to create new node to any set of node\n";
    cout<<"4 : create an algo to encrypt data\n";
    cout<<"5 : verify owner with key\n";
    cout<<"\n************************************************************\n";
        int num;
        cout<<"\nEnter choice:\n";
        cin>>num;


        if(num==11)
        break;



        if(num==1)
        {
            //cout<<"hi";
            input(-1,headnodes);
        }

        if(num==2)
        {
            cout<<"enter no. of sets\n";
            int sets;
            cin>>sets;

            while(sets--)
            {
                input(-1,headnodes);
            }
        }

        if(num==3)
        {
            int nodenum;
            cout<<"enter node number";
            cin>>nodenum;

            input(nodenum,headnodes);
        }

        if(num==4)
        {
            string password,algo;
            cout<<"Enter password and algo key";

            bool k=printverify(password,algo);
        }

        if(num==5)
        {
            string password,algo;
            cout<<"Enter password and algo key";

            bool k=printverify(password,algo);

            if(k)
            cout<<"verified";
            else
            cout<<"not verified";

            cout<<endl;
        }



    }

   return 0;
}