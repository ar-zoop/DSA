//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
   typedef struct huffman_node
   {
      struct huffman_node *left;
      struct huffman_node *right;
      char letter;
      int freq;

      //     bool operator <( const huffman_node &a ) const {
      //       return freq >a.freq;
      //   }
   } node;

   // ascending order me sort the priority queue. hence a min heap is formed.
   class cmp
   {
   public:
      bool operator()(const node *a, const node *b)
      {
         return b->freq < a->freq;
      }
   };
   node *create_node(char s, int f)
   {
      node *temp;
      temp = (node *)malloc(sizeof(node));
      temp->left = NULL;
      temp->right = NULL;
      temp->letter = s;
      temp->freq = f;
      return temp;
   }

   node *rearrange(node *x, node *y)
   {
      node *z = (node *)malloc(sizeof(node));
      z->left = x;
      z->right = y;
      z->freq = x->freq + y->freq;
      z->letter = '~';
      return z;
   }

   void traversal(node *n, string temp, vector<string> &ans)
   {
      if (n->left == NULL && n->right == NULL)
      {
         ans.push_back(temp);
         return;
      }

      traversal(n->left, temp + '0', ans);
      traversal(n->right, temp + '1', ans);
   }

   vector<string> huffmanCodes(string S, vector<int> f, int N)
   {
      vector<string> res;
      string temp;
      priority_queue<node *, vector<node *>, cmp> Q;
      for (int i = 0; i < N; i++)
      {
         node *Q_node = create_node(S[i], f[i]);
         Q.push(Q_node);
      }

      node *x, *y, *z;
      while (Q.size() != 1)
      {
         x = Q.top();
         //  cout<<"x= "<<x->freq;
         Q.pop();
         y = Q.top();
         //  cout<<" y= "<<y->freq<<endl;
         Q.pop();
         z = rearrange(x, y);
         Q.push(z);
      }
      traversal(z, temp, res);
      return res;
   }
};

//{ Driver Code Starts.
int main()
{
   int T;
   cin >> T;
   while (T--)
   {
      string S;
      cin >> S;
      int N = S.length();
      vector<int> f(N);
      for (int i = 0; i < N; i++)
      {
         cin >> f[i];
      }
      Solution ob;
      vector<string> ans = ob.huffmanCodes(S, f, N);
      for (auto i : ans)
         cout << i << " ";
      cout << "\n";
   }
   return 0;
}
// } Driver Code Ends