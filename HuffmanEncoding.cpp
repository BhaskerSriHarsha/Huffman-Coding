#include <bits/stdc++.h>
#include <string>
#include <sstream>

using namespace std;

#define SIZE 127

char CharArrayy[500];
int CharArrayIndex=0;
string HuffCode[500];

// A Huffman tree node
struct MinHeapNode
    {
    char data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)
    {

        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

// For comparison of
// two heap nodes (needed in min heap)
struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str)
{

    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << " " << str <<endl;
        //if(root->data != '$')
        {
            CharArrayy[CharArrayIndex]=root->data;//change chararray to y
            HuffCode[CharArrayIndex]=str;
            CharArrayIndex++;
        }
    if(root->left)
    {
      printCodes(root->left, str + "0");
    }
    if(root->right)
    {
      printCodes(root->right, str + "1");
    }
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top, *first, *second;

    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, deque<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
    {
        cout<<"Pushed: "<<data[i]<<" "<<freq[i]<<endl;
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }
    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {

        // Extract the two minimum
        // freq items from min heap
        first = minHeap.top();
        cout<<"Extracted first node: "<<first->data<<endl;
        minHeap.pop();

        second = minHeap.top();
        cout<<"Extracted second node: "<<second->data<<endl;
        minHeap.pop();

        if(first->freq == second->freq)
        {
          right=first;
          cout<<"right node is: "<<first->data<<endl;
          left=second;
          cout<<"left node is: "<<second->data<<endl;
        }
        else
        {
          left=first;
          cout<<"left node is: "<<first->data<<endl;
          right=second;
          cout<<"right node is: "<<second->data<<endl;
        }

        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print Huffman codes using
    // the Huffman tree built above
    printCodes(minHeap.top(), "");
}

void printCharWithFreq(string str)
{
    // size of the string 'str'
    int n = str.size();

    int freq[SIZE];
    memset(freq, 0, sizeof(freq));

    // accumulate freqeuncy of each character in 'str'
    for (int i = 0; i < n; i++)
        //freq[str[i] - 'a']++;
      {
        freq[str[i]]++;
      //  cout<<"Clue "<<str[i]<<" "<<(int)str[i]<<endl;
      }

      int size2 = sizeof(freq) / sizeof(freq[0]);
      //cout<<size2<<endl;

      for(int i=0;i<size2;i++)
      {
        cout<<(char)i<<" "<<freq[i]<<endl;
      }


    // traverse 'str' from left to right
    int ArrayPushVariable=0;
    char CharArray[127];
    int FrequencyArray[127];

    for (int i = 0; i < size2; i++)
    {
        if (freq[i] != 0)
        {
            CharArray[ArrayPushVariable]      = (char)i;
            FrequencyArray[ArrayPushVariable] = freq[i];
            cout<<"Pushed into char array: "<<(char)i<<" "<<freq[i]<<endl;

            ArrayPushVariable++;

            //freq[str[i]] = 0;
        }
    }

    cout<<CharArray<<endl;

    //declare two new arrays with size ArrayPushVariable
    int freq2[ArrayPushVariable];
    char arr[ArrayPushVariable];

    for(int i3=0;i3<ArrayPushVariable;i3++)
    {
      arr[i3]=CharArray[i3];
      freq2[i3]=FrequencyArray[i3];
    }

    for(int i4=0;i4<ArrayPushVariable;i4++)
    {
      cout<<"Charecter: "<<arr[i4]<<" "<<"Frequency: "<<freq2[i4]<<endl;
    }

    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, freq2, size);

    memset(arr, 0, sizeof(arr));
    memset(freq2, 0, sizeof(freq2));
    size=0;

}


int main()
{
    int NUmberOfTestCases;
    string e;

    scanf("%d",&NUmberOfTestCases);
    getline(cin,e);

    for(;NUmberOfTestCases>0;NUmberOfTestCases--)
    {
      //cout<<"Entered for loop"<<endl;
      string InputString ;
      getline(cin,InputString);
      printCharWithFreq(InputString);

    string BinaryOutputString;
    int InputStringPointer=0;

    for(;InputStringPointer<InputString.length();InputStringPointer++)
    {
      for(int i2=0;i2<CharArrayIndex;)
      {
        if(InputString[InputStringPointer]==CharArrayy[i2])//found in chararray set to y
        {
          BinaryOutputString=BinaryOutputString+HuffCode[i2];
          break;
        }
        else//Not found
        {
          i2++;
        }
      }
    }

    //cout<<BinaryOutputString<<endl;

    //See if length is multiple of 6 else append zeros
    if(BinaryOutputString.length()%6!=0)
    {
      int NumberOfZerosToAdd=0;
      NumberOfZerosToAdd=(BinaryOutputString.length()%6)-6;
      NumberOfZerosToAdd=abs(NumberOfZerosToAdd);

      for(;NumberOfZerosToAdd>0;NumberOfZerosToAdd--)
      {
        BinaryOutputString=BinaryOutputString+"0";
      }
    }

    //cout<<BinaryOutputString<<endl;

    for(int i3=0;i3<(BinaryOutputString.length()/6);i3++)
    {
      string BinaryOutputString2;
      for(int i4=i3*6;i4<((i3+1)*6);i4++)
      {
          BinaryOutputString2=BinaryOutputString2+BinaryOutputString[i4];
      }
      //time to convert into an integer and then to decimal
      //cout<<BinaryOutputString2<<endl;

      string input;
      input = BinaryOutputString2;
      //cout<<"From input variable: "<<input<<endl;
      int num=0, rem, temp, dec = 0, b = 1;

      stringstream geek(input);
      geek >> num;
      temp = num;
      while (temp > 0)
      {
          rem = temp % 10;
          dec = dec + rem * b;
          b *= 2;
          temp /= 10;
      }
      cout<<(char)(dec+48);

    }

    cout<<endl;
    memset(CharArrayy, 0, sizeof(CharArrayy));
    memset(HuffCode, 0, sizeof(HuffCode));
    CharArrayIndex=0;
    //return 0;
  }
}
