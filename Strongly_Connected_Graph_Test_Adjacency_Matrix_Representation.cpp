// For quick testing, visit this link https://www.programiz.com/online-compiler/23aLKcDIIJkFb

#include <iostream>
using namespace std;
// التحقق من ان بيان متصل بقوة بطريقة التخزين adjacency matrix
class Graph {
     public:
         int vertices;  // العقد
         int n;     cin>>n;
         // مصفوفة تخزن عدد الوصلات الداخلة الى كل عقدة
         int indegreeofnodes[n];
         // مصفوفة تخزن عدد الوصلات الخارجة من كل عقدة
         int outdegreeofnodes[n];
// باني بوسطاء         
        Graph( int v, int a[], int b[] )
          {       vertices=v;
                   for(int i=0;i<n;i++)
                      { indegreeofnodes[i]=a[i];
                        outdegreeofnodes[i]=b[i];  }
           }
       // تابع لاضافة وصلة الى البيان 
            void add_Edge ( int u)
           {         int k;     cin>>k;
                     for ( int i=0;i<n;i++)
                             if ( u==k ) 
                                indegreeofnodes[k]++;
            }
      // تابع للتهيئة خاص بتابع Dfs 
           void Depth_First_Search_Init()
           {         int dfs_count=1;
                     int finish_count=1;
                     int n;       cin>>n;
                     string state[n];
                     for (int i=0;i<n;i++)
                               state[i]="new";         }
// اختبار وجود وصلة بين عقدتين باستخدام مصفوفة الجوار
bool Is_connected(int adjmatrix[n][],int n,
                                   int u, int v)
      {
               if ( adjmatrix[u][v]==1 )
                        return true;
               else       return false;             
       }
// تابع البحث في العمق من اجل عقدة ما في البيان
                 void Dfs ( int x)
              {      state[x]="active";
                     int n;      cin>>n;
                     int dfs_num[n];
                     dfs_num[x]=dfs_count;
                     dfs_count++;      }
// اختبار وجود وصلة بين x وعقدة ما     
     if ( Is_connected(adjmatrix[n][],n,x,w))
        {         if state[w]=="new"
                         Dfs(w);
        }
      state[x]="finished";
       int n;      cin>>n;
       int finish_num[n];
       finish_num[x]=finish_count;
       finish_count++;
                        }
// تابع لعكس وصلات البيان 
         void swap_edges()
          {        int n;     cin>>n;
                    for(int i=0;i<n;i++)
swap(indegreeofnodes[i],outdegreeofnodes[i]);
           }
// تابع للتحقق من ان جميع العقد تمت زيارتها
            bool Is_visited()
              {       int c=0;    int n;   cin>>n;
                      for(int i=0;i<n;i++)
                             if(state[i]="finished")
                                        c++;
                      if(c==n)
                               return true;
                      else    return false;
               }
}; 

int main(){
            int a,b,c,n;    cin>>c>>n;
            int arr1[n];    int arr2[n];
            for(int i=0;i<n;i++)
             {          cin>>a>>b;
                         arr1[i]=a;
                         arr2[i]=b;     
              }
           Graph g(c,arr1,arr2);
           g.Depth_First_Search_Init();
           int u;      cin>>u;
           g.Dfs(u);
           bool g1=g.Is_Visited();
           g.swap_edges();
           bool g2=g.Is_Visited();
           if (g1==true&&g2==true)
                 cout<<"The graph is strongly connected";
            else 
                 cout<<"The graph is not strongly connected";
   
return 0; 
}