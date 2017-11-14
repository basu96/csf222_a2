#include<stdio.h>
/*
    no time to write comments. need to sleep :(
    Also, the code isn't in perfect state yet. Might wanna decrease precision if it takes too long to respond :)
*/

long double probability(int t,int node,long double probs[100][100],int n){
    /*Calculate probability of "node" at "t" */
    if(t == 0)
        if(node == 0) return 1;
        else return 0;

    int i;
    long double p = 0;
    for(i=0;i<n;i++){
        if(probs[i][node] == 0) continue;
        p += probability(t-1,i,probs,n)*probs[i][node];
    }
    return p;
}

int main(){
    int n,m,i,j;
    scanf("%d",&n);
    scanf("%d",&m);
    int matrix[100][101];
    long double probs[100][100];

    for(i=0;i<n;i++) for(j=0;j<n+1;j++) matrix[i][j] = probs[i][j] = 0;

    for(i=0;i<m;i++){
        int in1,in2;
        scanf("%d %d",&in1,&in2);
        matrix[in1][in2] = 1;
        matrix[in1][n]++;
    }

    for(i=0;i<n;i++){
        int count = 0;
        int factor = matrix[i][n];
        for(j=0;j<n;j++){
            if(factor == 0) probs[i][j] = 1/(float)n;
            else if(matrix[i][j] != 0) probs[i][j] = (1/((float)factor));
        }
    }

    long double precision = 0.0001,deviation=10;
    //precision is the the precision to which one wants the answer, since the output is float

    for(i=0;i<n;i++,deviation=10){
        int t = 15;
        // t is for testing purposes


        // long double p1=0,p2=1;
        // while(deviation>precision){
        //     p1 = probability(t,i,probs,n);
        //     p2 = probability(t-1,i,probs,n);
        //     t++;
        //     if(p2>p1) deviation = p2-p1;
        //     else deviation = p1-p2;
        // }
        // // printf("t=%d\n",t);
        // printf("%Lf\n",p1);

        printf("%Lf\n",probability(t,i,probs,n));
    }

    return 0;
}
