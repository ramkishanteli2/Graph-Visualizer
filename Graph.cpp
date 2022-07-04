#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include "GraphStructure.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Graph* createGraph(int v)
{
    struct Graph*G=(struct Graph*)malloc(sizeof(struct Graph));
    G->v=v;
    G->e=0;
    G->adj=(int **)malloc(sizeof(int *)*v);
    for(int i=0;i<v;i++)
    {
        G->adj[i]=(int *)malloc(sizeof(int)*v);
        for(int j=0;j<v;j++)
            G->adj[i][j]=0;
    }
    return G;
}
void draw_Graph(struct Graph * G)
{
    initwindow(500,500,"Graph");
    int arr[G->v][2];
    for(int i=0;i<G->v;i++)
    {
        srand(time(NULL));
        //delay(3*1000);
        arr[i][0]=((i+12)*rand())%500;
        arr[i][1]=((i+19)*rand())%500;
    }
    for(int i=0;i<G->v;i++)
    {
        int n=i+1,d=0;
        while(n)
        {
            d++;
            n/=10;
        }
        char ch[d+1];
        ch[d]='\0';
        n=i+1;
        while(n)
        {
            ch[--d]=48+n%10;
            n/=10;
        }
        circle(arr[i][0],arr[i][1],5);
        outtextxy(arr[i][0]+6,arr[i][1],ch);
    }
    //For setting color
    srand(time(NULL));
    setcolor(1+rand()%15);
    //End
    for(int i=0;i<G->v;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(G->adj[i][j]!=0)
                line(arr[i][0],arr[i][1],arr[j][0],arr[j][1]);
        }
    }
    getch();
}
void drawShortestPath(struct Graph *G,vector<int>vec)
{
    initwindow(500,500,"Graph");
    int arr[G->v][2];
    for(int i=0;i<G->v;i++)
    {
        srand(time(NULL));
        //delay(3*1000);
        arr[i][0]=((i+12)*rand())%500;
        arr[i][1]=((i+19)*rand())%500;
    }
    for(int i=0;i<G->v;i++)
    {
        int n=i+1,d=0;
        while(n)
        {
            d++;
            n/=10;
        }
        char ch[d+1];
        ch[d]='\0';
        n=i+1;
        while(n)
        {
            ch[--d]=48+n%10;
            n/=10;
        }
        circle(arr[i][0],arr[i][1],5);
        outtextxy(arr[i][0]+6,arr[i][1],ch);
    }
    //For setting color
    srand(time(NULL));
    int clr=1+rand()%15;
    setcolor(clr);
    //End
    for(int i=0;i<G->v;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(G->adj[i][j]!=0)
                line(arr[i][0],arr[i][1],arr[j][0],arr[j][1]);
        }
    }
    int clr2=1+(1+clr)%15;
    setcolor(clr2);
    for(int i=0;i<vec.size()-1;i++)
        line(arr[vec[i]][0],arr[vec[i]][1],arr[vec[i+1]][0],arr[vec[i+1]][1]);
    setcolor(WHITE);
    for(int i=0;i<vec.size()-1;i++)
    {
        float x1=arr[vec[i]][0],y1=arr[vec[i]][1],x2=arr[vec[i+1]][0],y2=arr[vec[i+1]][1];
        //circle(x1,x2,1);
        float m=(y2-y1)/(x2-x1);
        float c=(y1-m*x1);
        float x=x1;
        float y=m*x1+c;
        if(x1<x2)
        {
            circle(x,y,5);
            setfillstyle(SOLID_FILL,rand()%15);
            floodfill(x,y,WHITE);
            while(x<=x2)
            {
                x=x+1.01;
                y=m*x+c;
                delay(10);
                cleardevice();
                for(int i=0; i<G->v; i++)
                {
                    int n=i+1,d=0;
                    while(n)
                    {
                        d++;
                        n/=10;
                    }
                    char ch[d+1];
                    ch[d]='\0';
                    n=i+1;
                    while(n)
                    {
                        ch[--d]=48+n%10;
                        n/=10;
                    }
                    circle(arr[i][0],arr[i][1],5);
                    outtextxy(arr[i][0]+6,arr[i][1],ch);
                }
                //For setting color
                srand(time(NULL));
                setcolor(clr);
                //End
                for(int i=0; i<G->v; i++)
                {
                    for(int j=0; j<i; j++)
                    {
                        if(G->adj[i][j]!=0)
                            line(arr[i][0],arr[i][1],arr[j][0],arr[j][1]);
                    }
                }
                setcolor(clr2);
                for(int i=0; i<vec.size()-1; i++)
                    line(arr[vec[i]][0],arr[vec[i]][1],arr[vec[i+1]][0],arr[vec[i+1]][1]);
                setcolor(WHITE);
                circle(x,y,5);
                setfillstyle(SOLID_FILL,rand()%15);
                floodfill(x,y,WHITE);
            }
        }
        else
        {
            circle(x,y,5);
            setfillstyle(SOLID_FILL,rand()%15);
            floodfill(x,y,WHITE);
            while(x>=x2)
            {
                x=x-1.01;
                y=m*x+c;
                delay(10);
                cleardevice();
                for(int i=0; i<G->v; i++)
                {
                    int n=i+1,d=0;
                    while(n)
                    {
                        d++;
                        n/=10;
                    }
                    char ch[d+1];
                    ch[d]='\0';
                    n=i+1;
                    while(n)
                    {
                        ch[--d]=48+n%10;
                        n/=10;
                    }
                    circle(arr[i][0],arr[i][1],5);
                    outtextxy(arr[i][0]+6,arr[i][1],ch);
                }
                //For setting color
                srand(time(NULL));
                setcolor(clr);
                //End
                for(int i=0; i<G->v; i++)
                {
                    for(int j=0; j<i; j++)
                    {
                        if(G->adj[i][j]!=0)
                            line(arr[i][0],arr[i][1],arr[j][0],arr[j][1]);
                    }
                }
                setcolor(clr2);
                for(int i=0; i<vec.size()-1; i++)
                    line(arr[vec[i]][0],arr[vec[i]][1],arr[vec[i+1]][0],arr[vec[i+1]][1]);
                setcolor(WHITE);
                circle(x,y,5);
                setfillstyle(SOLID_FILL,rand()%15);
                floodfill(x,y,WHITE);
            }
        }
    }

    getch();

}
void insertEdge(struct Graph *G,int u,int v,int weight=1)
{
        G->adj[u-1][v-1]=weight;
        G->adj[v-1][u-1]=weight;
        (G->e)++;
}
void printAdjMatrix(struct Graph *G)
{
    for(int i=0;i<G->v;i++)
    {
        for(int j=0;j<G->v;j++)
            printf("%d ",G->adj[i][j]);
        printf("\n");
    }
}
struct Graph* buildSpanningTree(struct Graph*G)
{
    struct Graph*STree= (struct Graph *)malloc(sizeof(struct Graph));
    STree->v=G->v;
    STree->e=0;
    STree->adj=(int **)malloc(sizeof(int *)*STree->v);
    for(int i=0; i<STree->v; i++)
    {
        STree->adj[i]=(int *)malloc(sizeof(int)*STree->v);
        for(int j=0; j<STree->v; j++)
            STree->adj[i][j]=0;
    }
    vector<vector<int> >vec(1);
    vector<pair<int,int> >edges;
    for(int i=0; i<G->v; i++)
        for(int j=0; j<i; j++)
            if(G->adj[i][j]==1)
                edges.push_back(pair<int,int>(i,j));
    vec[0].push_back(edges.back().first);
    vec[0].push_back(edges.back().second);
    STree->adj[edges.back().first][edges.back().second]=1;
    STree->adj[edges.back().second][edges.back().first]=1;
    STree->e+=1;
    edges.pop_back();
    while(!edges.empty())
    {
        int bucket_no1=-1;
        int bucket_no2=-1;
        for(int i=0;i<vec.size();i++)
        {
            if(find(vec[i].begin(),vec[i].end(),edges.back().first)!=vec[i].end())
                bucket_no1=i;
            if(find(vec[i].begin(),vec[i].end(),edges.back().second)!=vec[i].end())
                bucket_no2=i;
            if(bucket_no1!=-1 && bucket_no2!=-1)
                break;
        }
        if(bucket_no1==-1 && bucket_no2==-1)
        {
            vec.push_back(vector<int>(1,edges.back().first));
            vec.back().push_back(edges.back().second);
            STree->adj[edges.back().first][edges.back().second]=1;
            STree->adj[edges.back().second][edges.back().first]=1;
            STree->e+=1;
            edges.pop_back();
        }
        else if(bucket_no1==bucket_no2)
            edges.pop_back();
        else if(bucket_no1!=-1 && bucket_no2!=-1 && bucket_no1!=bucket_no2)
        {
            while(!vec[bucket_no2].empty())
            {
                vec[bucket_no1].push_back(vec[bucket_no2].back());
                vec[bucket_no2].pop_back();
            }
            STree->adj[edges.back().first][edges.back().second]=1;
            STree->adj[edges.back().second][edges.back().first]=1;
            STree->e+=1;
            edges.pop_back();
        }
        else
        {
            if(bucket_no1==-1 && bucket_no2!=-1)
            {
                vec[bucket_no2].push_back(edges.back().first);
                STree->adj[edges.back().first][edges.back().second]=1;
                STree->adj[edges.back().second][edges.back().first]=1;
                STree->e+=1;
                edges.pop_back();
            }
            else if(bucket_no1!=-1 && bucket_no2==-1)
            {
                vec[bucket_no1].push_back(edges.back().second);
                STree->adj[edges.back().first][edges.back().second]=1;
                STree->adj[edges.back().second][edges.back().first]=1;
                STree->e+=1;
                edges.pop_back();
            }
        }
        int flag1=0,flag2=0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i].size()==STree->v)
                flag1=1;
            else
                if(vec[i].size()!=0)
                    flag2=1;
        }
        if((flag1==1 && flag2==0) && STree->v==STree->e+1)
            return STree;
    }
    for(int i=0;i<STree->v;i++)
        free(STree->adj[i]);
    free(STree->adj);
    free(STree);
    return NULL;
}
//Kruskal's Algorithm for finding minimum spanning tree
//It takes graph as an argument and return the Minimum Spanning Tree
struct Graph* buildMinimumSpanningTree(struct Graph*G)
{
    //Memory allocation for spanning Tree
    struct Graph*STree= (struct Graph *)malloc(sizeof(struct Graph));
    STree->v=G->v;
    STree->e=0;
    //Memory allocation for adjacency matrix of spanning tree
    STree->adj=(int **)malloc(sizeof(int *)*STree->v);
    //Initially all entries of adjacency matrix set to 0
    for(int i=0; i<STree->v; i++)
    {
        STree->adj[i]=(int *)malloc(sizeof(int)*STree->v);
        for(int j=0; j<STree->v; j++)
            STree->adj[i][j]=0;
    }
    //Here this vector of vector is used for buckets It will grow its size as
    //number of buckets increase
    vector<vector<int> >vec(1);
    //This is vector of pair this represents the edges of graph, pair contains
    //source vertex and destination vertex of an edge
    vector<pair<int,int> >edges;
    for(int i=0; i<G->v; i++)
        for(int j=0; j<i; j++)
            if(G->adj[i][j]!=0)
                edges.push_back(pair<int,int>(i,j));

    //Sorting of edges according to theirs weights
    //I used here bubble sort Here I have sort the edges in decreasing order of their used
    //Because I choose the edge from the end
    for(int i=0;i<edges.size()-1;i++)
    {
        for(int j=0;j<edges.size()-1-i;j++)
        {
            if(G->adj[edges[j].first][edges[j].second]<G->adj[edges[j+1].first][edges[j+1].second])
            {
                pair<int,int>temp=edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;

            }
        }
    }
    //Here first minimum weighted edge is taken and and its both end points are inserted into an
    //empty bucket
    vec[0].push_back(edges.back().first);
    vec[0].push_back(edges.back().second);
    STree->adj[edges.back().first][edges.back().second]=G->adj[edges.back().first][edges.back().second];
    STree->adj[edges.back().second][edges.back().first]=G->adj[edges.back().first][edges.back().second];
    STree->e+=1;
    edges.pop_back();
    //This loop runs until all the edges will examined
    while(!edges.empty())
    {
        //Here I am finding that the end points of the minimum weight edge are lying in which
        //buckets
        int bucket_no1=-1;
        int bucket_no2=-1;
        for(int i=0;i<vec.size();i++)
        {
            if(find(vec[i].begin(),vec[i].end(),edges.back().first)!=vec[i].end())
                bucket_no1=i;
            if(find(vec[i].begin(),vec[i].end(),edges.back().second)!=vec[i].end())
                bucket_no2=i;
            if(bucket_no1!=-1 && bucket_no2!=-1)
                break;
        }
        //If bucket_no1 or bucket_no2 is equal to -1 then they are not found in any bucket
        //Case 1
        //If both the ends points are none of the bucket put both end points of edge in
        //a new empty bucket and select this edge
        if(bucket_no1==-1 && bucket_no2==-1)
        {
            vec.push_back(vector<int>(1,edges.back().first));
            vec.back().push_back(edges.back().second);
            STree->adj[edges.back().first][edges.back().second]=G->adj[edges.back().first][edges.back().second];
            STree->adj[edges.back().second][edges.back().first]=G->adj[edges.back().first][edges.back().second];
            STree->e+=1;
            edges.pop_back();
        }
        //Case 2
        //If both the end points are in same bucket then discard this edge
        else if(bucket_no1==bucket_no2)
            edges.pop_back();
        //Case 3
        //If one end point in one bucket and another end point in another bucket then
        //merge both the buckets in a single bucket and select this edge
        else if(bucket_no1!=-1 && bucket_no2!=-1 && bucket_no1!=bucket_no2)
        {
            while(!vec[bucket_no2].empty())
            {
                vec[bucket_no1].push_back(vec[bucket_no2].back());
                vec[bucket_no2].pop_back();
            }
            STree->adj[edges.back().first][edges.back().second]=G->adj[edges.back().first][edges.back().second];
            STree->adj[edges.back().second][edges.back().first]=G->adj[edges.back().first][edges.back().second];
            STree->e+=1;
            edges.pop_back();
        }
        else
        {
            //Case 4
            //If one end point in a bucket and another end point is in no bucket then add another end
            //point in the same bucket and select this edge
            if(bucket_no1==-1 && bucket_no2!=-1)
            {
                vec[bucket_no2].push_back(edges.back().first);
                STree->adj[edges.back().first][edges.back().second]=G->adj[edges.back().first][edges.back().second];
                STree->adj[edges.back().second][edges.back().first]=G->adj[edges.back().first][edges.back().second];
                STree->e+=1;
                edges.pop_back();
            }
            else if(bucket_no1!=-1 && bucket_no2==-1)
            {
                vec[bucket_no1].push_back(edges.back().second);
                STree->adj[edges.back().first][edges.back().second]=G->adj[edges.back().first][edges.back().second];
                STree->adj[edges.back().second][edges.back().first]=G->adj[edges.back().first][edges.back().second];
                STree->e+=1;
                edges.pop_back();
            }
        }
        //If all the vertices are in same bucket or number of edges are equal to the one less than the
        //vertices then stop the algorithm because we get the required spanning tree.
        int flag1=0,flag2=0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i].size()==STree->v)
                flag1=1;
            else
                if(vec[i].size()!=0)
                    flag2=1;
        }
        //If Tree found then return the address of Minimum Spanning Tree
        if((flag1==1 && flag2==0) && STree->v==STree->e+1)
            return STree;
    }
    //If no such tree found then releasing the memory and returning NULL
    for(int i=0;i<STree->v;i++)
        free(STree->adj[i]);
    free(STree->adj);
    free(STree);
    return NULL;
}
struct Graph* buildMaximumSpanningTree(struct Graph*G)
{
    struct Graph*STree= (struct Graph *)malloc(sizeof(struct Graph));
    STree->v=G->v;
    STree->e=0;
    STree->adj=(int **)malloc(sizeof(int *)*STree->v);
    for(int i=0; i<STree->v; i++)
    {
        STree->adj[i]=(int *)malloc(sizeof(int)*STree->v);
        for(int j=0; j<STree->v; j++)
            STree->adj[i][j]=0;
    }
    vector<vector<int> >vec(1);
    vector<pair<int,int> >edges;
    for(int i=0; i<G->v; i++)
        for(int j=0; j<i; j++)
            if(G->adj[i][j]!=0)
                edges.push_back(pair<int,int>(i,j));
    for(int i=0;i<edges.size()-1;i++)
    {
        for(int j=0;j<edges.size()-1-i;j++)
        {
            if(G->adj[edges[j].first][edges[j].second]>G->adj[edges[j+1].first][edges[j+1].second])
            {
                pair<int,int>temp=edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;

            }
        }
    }
    vec[0].push_back(edges.back().first);
    vec[0].push_back(edges.back().second);
    STree->adj[edges.back().first][edges.back().second]=G->adj[edges.back().first][edges.back().second];
    STree->adj[edges.back().second][edges.back().first]=G->adj[edges.back().first][edges.back().second];
    STree->e+=1;
    edges.pop_back();
    while(!edges.empty())
    {
        int bucket_no1=-1;
        int bucket_no2=-1;
        for(int i=0;i<vec.size();i++)
        {
            if(find(vec[i].begin(),vec[i].end(),edges.back().first)!=vec[i].end())
                bucket_no1=i;
            if(find(vec[i].begin(),vec[i].end(),edges.back().second)!=vec[i].end())
                bucket_no2=i;
            if(bucket_no1!=-1 && bucket_no2!=-1)
                break;
        }
        if(bucket_no1==-1 && bucket_no2==-1)
        {
            vec.push_back(vector<int>(1,edges.back().first));
            vec.back().push_back(edges.back().second);
            STree->adj[edges.back().first][edges.back().second]=G->adj[edges.back().first][edges.back().second];
            STree->adj[edges.back().second][edges.back().first]=G->adj[edges.back().first][edges.back().second];
            STree->e+=1;
            edges.pop_back();
        }
        else if(bucket_no1==bucket_no2)
            edges.pop_back();
        else if(bucket_no1!=-1 && bucket_no2!=-1 && bucket_no1!=bucket_no2)
        {
            while(!vec[bucket_no2].empty())
            {
                vec[bucket_no1].push_back(vec[bucket_no2].back());
                vec[bucket_no2].pop_back();
            }
            STree->adj[edges.back().first][edges.back().second]=G->adj[edges.back().first][edges.back().second];
            STree->adj[edges.back().second][edges.back().first]=G->adj[edges.back().first][edges.back().second];
            STree->e+=1;
            edges.pop_back();
        }
        else
        {
            if(bucket_no1==-1 && bucket_no2!=-1)
            {
                vec[bucket_no2].push_back(edges.back().first);
                STree->adj[edges.back().first][edges.back().second]=G->adj[edges.back().first][edges.back().second];
                STree->adj[edges.back().second][edges.back().first]=G->adj[edges.back().first][edges.back().second];
                STree->e+=1;
                edges.pop_back();
            }
            else if(bucket_no1!=-1 && bucket_no2==-1)
            {
                vec[bucket_no1].push_back(edges.back().second);
                STree->adj[edges.back().first][edges.back().second]=G->adj[edges.back().first][edges.back().second];
                STree->adj[edges.back().second][edges.back().first]=G->adj[edges.back().first][edges.back().second];
                STree->e+=1;
                edges.pop_back();
            }
        }
        int flag1=0,flag2=0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i].size()==STree->v)
                flag1=1;
            else
                if(vec[i].size()!=0)
                    flag2=1;
        }
        if((flag1==1 && flag2==0) && STree->v==STree->e+1)
            return STree;
    }
    for(int i=0;i<STree->v;i++)
        free(STree->adj[i]);
    free(STree->adj);
    free(STree);
    return NULL;
}
struct Graph*primsAlgorithmMinimumSpanningTree(struct Graph* G)
{
    struct Graph* STree=new Graph;
    STree->v=0;
    STree->e=0;
    STree->adj=new int*[G->v];
    int arr[G->v][G->v];
    for(int i=0;i<G->v;i++)
    {
        STree->adj[i]=new int[G->v];
        for(int j=0;j<G->v;j++)
        {
            STree->adj[i][j]=0;
            arr[i][j]=G->adj[i][j];
        }
    }
    vector<int>takenVertices;
    takenVertices.push_back(0);
    (STree->v)++;
    while(!(takenVertices.size()==G->v))
    {
        int min=1000000000,source=-1,destination=-1;
        for(int i=0;i<takenVertices.size();i++)
        {
            for(int j=0;j<G->v;j++)
            {
                if(arr[takenVertices[i]][j]!=-1 && arr[takenVertices[i]][j]!=0 && min>arr[takenVertices[i]][j])
                {
                    min=arr[takenVertices[i]][j];
                    source=takenVertices[i];
                    destination=j;
                }
            }
        }
        if(destination==-1)
            return NULL;
        if(find(takenVertices.begin(),takenVertices.end(),destination)==takenVertices.end())
        {
            takenVertices.push_back(destination);
            STree->adj[source][destination]=min;
            STree->adj[destination][source]=min;
            (STree->e)++;
            (STree->v)++;
            arr[source][destination]=-1;
            arr[destination][source]=-1;
        }
        else
        {
            arr[source][destination]=-1;
            arr[destination][source]=-1;
        }
    }
    return STree;
}
int minKey(int key[],bool mstSet[],int v)
{
    int min=INT_MAX,index;
    for(int i=0;i<v;i++)
        if(mstSet[i]==false && min>key[i])
            min=key[i],index=i;
    return index;
}
struct Graph*primsAlgorithm(struct Graph* G)
{
    struct Graph *STree= new Graph;
    STree->v=G->v;
    STree->e=G->v-1;
    STree->adj=new int*[G->v];
    for(int i=0;i<G->v;i++)
    {
        STree->adj[i]=new int[G->v];
        for(int j=0;j<G->v;j++)
            STree->adj[i][j]=0;
    }
    int key[G->v];
    int parent[G->v];
    bool mstSet[G->v];
    for(int i=0;i<G->v;i++)
        key[i]=INT_MAX,mstSet[i]=false;
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<G->v-1;i++)
    {
        int u=minKey(key,mstSet,G->v);
        mstSet[u]=true;
        for(int j=0;j<G->v;j++)
        {
            if(G->adj[u][j] && mstSet[j]==false && G->adj[u][j]<key[j])
                key[j]=G->adj[u][j],parent[j]=u;
        }
    }
    for(int i=1;i<G->v;i++)
    {
        STree->adj[parent[i]][i]=G->adj[parent[i]][i];
        STree->adj[i][parent[i]]=G->adj[parent[i]][i];
    }
    return STree;
}
int minWeight(int distance[],bool selected[],int v)
{
    int min=INT_MAX,index;
    for(int i=0;i<v;i++)
        if(selected[i]==false && min>distance[i])
            min=distance[i],index=i;
    return index;
}
vector<int> dijkstraalgorithm(struct Graph *G)
{
    int distance[G->v];
    int par[G->v],source;
    bool selected[G->v];
    for(int i=0;i<G->v;i++)
    {
        distance[i]=INT_MAX;
        selected[i]=false;
        par[i]=-1;
    }
    cout<<"Enter source vertex number: \n";
    cin>>source;
    distance[source-1]=0;
    par[source-1]=-1;
    for(int i=0;i<G->v;i++)
    {
        int u=minWeight(distance,selected,G->v);
        selected[u]=true;
        for(int j=0;j<G->v;j++)
            if(G->adj[u][j] && distance[j]> distance[u]+G->adj[u][j])
                distance[j]=distance[u]+G->adj[u][j],par[j]=u;
    }
    for(int i=0;i<G->v;i++)
        cout<<"\nShortest distance from: "<<source<<" to "<<i+1<<" is: "<<distance[i];
    cout<<"\nEnter vertex number for which you want to print shortest path:\n";
    int destination;
    cin>>destination;
    vector<int>vec;
    while(par[destination-1]!=-1)
    {
        //cout<<destination<<"-> ";
        vec.push_back(destination-1);
        destination=par[destination-1]+1;
    }
    vec.push_back(source-1);
    reverse(vec.begin(),vec.end());
    return vec;
}//8 11 1 2 2 1 4 1 1 3 11 2 5 10 2 4 9 4 5 3 4 6 1 3 6 20 6 7 8 7 8 3 3 8 1
void DFSAlgorithm(struct Graph* G,int start,bool *visited)
{
    cout<<start<<" ";
    visited[start-1]=true;
    for(int i=0;i<G->v;i++)
    {
        if(visited[i]==false && G->adj[start-1][i])
            DFSAlgorithm(G,i+1,visited);
    }
}
void BFSAlgorithm(struct Graph*G,int start,int*visited)
{
    queue<int>q;
    q.push(start);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        visited[u]=2;
        for(int i=0;i<G->v;i++)
            if(visited[i]==0 && G->adj[u][i])
            {
                q.push(i);
                visited[i]=1;
            }
    }
}
void DFSOnDisconnectedGraph(struct Graph *G)
{
    bool visited[G->v];
    for(int i=0;i<G->v;i++)
        visited[i]=false;
    for(int i=0;i<G->v;i++)
        if(visited[i]==false)
            DFSAlgorithm(G,i,visited);
}
void BFSOnDisconnectedGraph(struct Graph*G)
{
    int visited[G->v];
    for(int i=0;i<G->v;i++)
        visited[i]=0;
    for(int i=0;i<G->v;i++)
        if(visited[i]==0)
            BFSAlgorithm(G,i,visited);
}
void insertEdge1(struct Graph *G,int u,int v,int weight=1)
{
    G->adj[u][v]=weight;
    G->adj[v][u]=weight;
    (G->e)++;
}
bool hasPath(struct Graph*G,int source,int destination,bool visited[])
{
    if(source==destination)
        return true;
    visited[source]=true;
    bool q=false;
    for(int i=0;i<G->v;i++)
        if(visited[i]==false && G->adj[source][i])
        {
            bool r=hasPath(G,i,destination,visited);
            q=q+r;
            if(r)
                cout<<i<<"->";
        }
    return q;
}
int main()
{
    int v,e;
    cout<<"Enter number of vertices in the graph: ";
    cin>>v;
    struct Graph *G=createGraph(v);
    cout<<"Enter number of edges in the graph: ";
    cin>>e;
    cout<<"Enter edges details: "<<endl;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cout<<"Enter vertex for edge - "<<i+1<<endl;
        cin>>u>>v;
        cout<<"Enter weight:"<<endl;
        cin>>w;
        insertEdge(G,u,v,w);
    }
    vector<int>vec=dijkstraalgorithm(G);
    //draw_Graph(G);
    drawShortestPath(G,vec);
    /*struct Graph* MinimumSpanningTree=buildMinimumSpanningTree(G);
    printAdjMatrix(MinimumSpanningTree);
    draw_Graph(MinimumSpanningTree);
    /*printAdjMatrix(G);
    printf("\n");
    struct Graph *SpanningTree=primsAlgorithm(G);
    cout<<endl;
    if(SpanningTree==NULL)
        cout<<"No Spanning Tree possible for given Graph";
    else
        printAdjMatrix(SpanningTree);
    //draw_Graph(SpanningTree);
    //printAdjMatrix(SpanningTree);
    //draw_Graph(G);
    //getch();
    if(SpanningTree==NULL)
        cout<<"No Spanning Tree possible for given Graph";
    else
        draw_Graph(SpanningTree);*/

    return 0;
}
