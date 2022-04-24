#include <iostream>
#include <bits/stdc++.h>

//2 way sort only
using namespace std;

int sizeofpage;
int buf;
//int maxpages;

class page{
public:
    vector<int> records;
    int numofrecords;
    page(){
        numofrecords=0;
    }

    void addrec(int val){
        records.push_back(val);
        numofrecords++;
    }

    void extsort(){
        sort(records.begin(),records.end());
    }

    void show(){
        for(int i=0;i<numofrecords;i++){
            cout<<records[i]<<endl;
        }
    }
};


class file{
    public:
    vector<page> filepages;
    vector<page> file2;
    int coun2;

    int numofpages;
    file(){
        numofpages=0;
        coun2=0;
    }
    void addpage(){
        page page2;
        filepages.push_back(page2);
        numofpages++;
    }
    void addrec(int val){
        (filepages[numofpages-1]).addrec(val);
    }
    void extsort(){
        /*for(int i=0;i<numofpages;i++){
            page page3;
            file2.push_back(page3);
            coun2 = numofpages;

        }*/
        file2 = filepages;
        for(int i=0;i<numofpages;i++){
            filepages[i].extsort();
        }

        mergesort(0,numofpages-1);
        //filepages = file2;

    }

    void mergesort(int pge1,int pge2){
        if(pge1<pge2){
            int mid = (pge1 + pge2)/2;
        mergesort(pge1,mid);
        mergesort(mid+1,pge2);
        mergee(pge1,mid,pge2);

        }


    }

    void mergee(int first,int mid,int last){
        int rec1=0;
        int rec2=0;

        int outp = first;
        int outr=0;

        int pg1=first;
        int pg2 = mid+1;

        while(pg1<=mid && pg2 <= last){


            int tmp1=filepages[pg1].records[rec1];
            int tmp2=filepages[pg2].records[rec2];

            if(tmp1 < tmp2){
                file2[outp].records[outr] = tmp1;
                rec1++;
                outr++;
            }
            else{
                file2[outp].records[outr] = tmp2;
                rec2++;
                outr++;
            }

            if(outr==sizeofpage){
                outp++;
                outr=0;
            }
            if(rec1 == filepages[pg1].numofrecords ){
                pg1++;
                rec1=0;
            }
            if(rec2 == filepages[pg2].numofrecords){
                pg2++;
                rec2=0;
            }
        }
        if(pg1 == mid+1 && pg2!=last+1){
            while(pg2<=last){

            int tmp2=filepages[pg2].records[rec2];

            (file2[outp]).records[outr] = tmp2;
            rec2++;
            outr++;

            if(outr==sizeofpage){
            outp++;
            outr=0;
            }
            if(rec2 == filepages[pg2].numofrecords){
            pg2++;
            rec2=0;
            }
            }

        }
        else if(pg2 == last+1 && pg1!=mid+1){
            while(pg1<=mid){

            int tmp1=filepages[pg1].records[rec1];

            (file2[outp]).records[outr] = tmp1;
            rec1++;
            outr++;

            if(outr==sizeofpage){
            outp++;
            outr=0;
            }
            if(rec1 == filepages[pg1].numofrecords){
            pg1++;
            rec1=0;
            }

            }


        }
        //done atoring in file2;
        for(int i=first;i<=last;i++){
            filepages[i]= file2[i];
        }


    }
    void show(){
        //cout<<"start"<<endl;
        for(int i=0;i<numofpages;i++){
            filepages[i].show();
        }
    }
};

//file file2;

int main()
{
    cin>>buf;
    cin>>sizeofpage;
    int num;
    cin>>num;
    file file1;
    int c;

    for(int i=0;i<num;i++){
        cin>>c;
        if(i%sizeofpage==0 ){
            file1.addpage();
        }
        file1.addrec(c);
    }

    file1.extsort();
    file1.show();

    return 0;
}
