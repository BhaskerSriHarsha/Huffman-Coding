#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

struct node
{
char data;
node *left;
node *right;
};

struct node *createNode() {
	struct node *newNode = new node;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = '$';
	return newNode;
}

//struct node *root = createNode();

void inorder(struct node *root)
{
	if(!root)
		return;

	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}

int main()
{
string input,e;

int NumberOfTestCases;
//cout<<"Enter the number of test cases: "<<endl;
cin>>NumberOfTestCases;

for(;NumberOfTestCases>0;NumberOfTestCases--)
{

int NumberOfCharecters;
//cout<<"Enter the number of charecters: "<<endl;
cin>>NumberOfCharecters;

int Extra;
//cout<<"Enter the number of extra bits"<<endl;
cin>>Extra;
getline(cin,e);

//Maybe build the huffman tree here itself by opening a for loop
struct node *root = createNode();
for(;NumberOfCharecters>0;NumberOfCharecters--)
{
	string inputline;
	getline(cin,inputline);
	char ch=inputline[0];
	string bin;
	bin = inputline.substr(2);
	//cout<<"bin is here: "<<bin<<endl;
	//cout<<ch<<" "<<bin<<endl;

	struct node *p = root;

	for(int i6=0;i6<bin.length();i6++)
	{
		if(bin[i6]=='0')
		{
			//cout<<"saw zero"<<endl;
			if(p->left == NULL)
				p->left=createNode();
			//	cout<<"Created node to the left"<<endl;
			p = p->left;
			//cout<<"Moved left"<<endl;
		}
		else
		{
			//cout<<"saw one"<<endl;
			if(p->right == NULL)
				p->right=createNode();
			//	cout<<"Created node to the right"<<endl;
			p = p->right;
			//cout<<"Moved right"<<endl;
		}
	}

	p->data = ch;
  //inorder(root);
}



getline(cin,input);
//cout<<input<<endl;

//Convert charecter to ascii values
vector <int > BinaryOfChar;
for(int i=0;i<input.length();i++)
{
//The ascii value of the charecter is (int)input[i]-48;
  int a[10], n, i3;
  n=(int)input[i]-48;
	int lengthCount=0;

  for(i3=0; n>0; i3++)
  {
    a[i3]=n%2;
		lengthCount++;
    n= n/2;
  }

	if(lengthCount<6)
	{
		for(int i=0;i<(6-lengthCount);i++)
		{
			BinaryOfChar.push_back(0);
		}
	}
//cout<<"Binary of the given number= ";
  for(i3=i3-1 ;i3>=0 ;i3--)
  {
    BinaryOfChar.push_back(a[i3]);
  }


  for(int i=0;i<BinaryOfChar.size();i++)
  {
	  //cout<<BinaryOfChar[i];
  }
  //cout<<endl;
}
/*
cout<<"Original binary code before deleting is: ";
for(int i=0;i<BinaryOfChar.size();i++)
{
	cout<<BinaryOfChar[i];
}
cout<<endl;
*/

//Creating a new vector which has zeros removed
vector <int> EditedBinaryVector;
if (Extra == 0){Extra=6;}

for(int i2=0;i2<BinaryOfChar.size()-(6-Extra);i2++)
{
  EditedBinaryVector.push_back(BinaryOfChar[i2]);
}
/*
cout<<"Binary code after removal is: ";
for(int i=0;i<EditedBinaryVector.size();i++)
{
	cout<<EditedBinaryVector[i];
}
cout<<endl;
*/

//The entire binary code is now inside EditedBinaryVector
//inorder(root);
struct node*p = root;

for(int i7=0;i7<EditedBinaryVector.size();i7++)
{
	if(EditedBinaryVector[i7]==0)
	{
		p = p->left;

		if(p->left == NULL &&  p->right == NULL)
		{
			cout<<p->data;
			p = root;
		}
	}
	else
	{
		p=p->right;
		if(p->left == NULL &&  p->right == NULL)
		{
			cout<<p->data;
			p = root;
		}
	}
}

cout<<endl;

}
return 0;
}
