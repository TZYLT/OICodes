#include<bits/stdc++.h>
using namespace std;
int main(){
    string n,p;
    printf("Name:");
    cin>>n;
    n=n+".code-snippets";
    char name[1000];
    for(int i=0;i<n.size();i++)
		name[i]=n[i];

    freopen(n.c_str(),"w",stdout);
	clog<<"Done!"<<endl;

	clog<<"prefix:";
	printf("{\n");
	printf("\t\"Print to console\": {\n");
	printf("\t\t\"scope\": \"cpp,c++\",\n");
	cin>>p;
	p="\t\t\"prefix\": \""+p+"\",\n";
	cout<<p;
	clog<<"Done!"<<endl;

	clog<<"Code:";
	printf("\t\t\"body\": [\n");
	string c;int sum=0;
	while(getline(cin,c)){
		if(c[0]=='d'&&c[1]=='o'&&c[2]=='n'&&c[3]=='e')break;
		printf("\t\t\t\"");
		cout<<c;
		printf("\",\n");
		sum++;
	}
	printf("\t\t],\n");
	clog<<"Done!Get "<<sum<<" line(s)."<<endl;

	clog<<"Description:";
	string d;
	getline(cin,d);
	d="\t\t\"description\": \""+d+"\"\n\t}\n}";
	cout<<d;
	n="move "+n+" .\\.vscode\\"+n;
	fflush(stdout);
	fclose(stdout);
	system(n.c_str());
	clog<<"Finished!\nAgain?(0/1):";
}

