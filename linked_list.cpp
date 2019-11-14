#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

struct point
{
	ll x;
	ll y;
};

struct node
{
	struct point p;
	struct node* next;
};

struct node* createnode (){

	struct node* newnode =(struct node*)malloc(sizeof(struct node));
	return newnode;
}

void addFirst(struct node** head, ll x, ll y ){

	struct node* newnode=createnode();
	newnode->p.x=x;
	newnode->p.y=y;
	newnode->next=*head;
	*head=newnode;

}

long long search (struct node* head, ll x, ll y){

	struct node* temp;
	temp=head;
	long long cnt=0;
	while(temp!=NULL){
		if (temp->p.x==x && temp->p.y==y)cnt++;
		temp=temp->next;

	}

	//if (cnt==0)cout<<"-1"<<endl;

	return cnt;
}

void delFirst(struct node** head){

      if(*head==NULL){
            cout<<"-1"<<endl;
            return;
      }

	struct node*temp;

	temp=*head;
	*head=(*head)->next;
	free(temp);
}

void del(struct node** head, ll x, ll y){

	if (search(*head, x, y)==0){
            cout<<"-1"<<endl;
            return;
	}

	else{

		struct node* temp;
		struct node* prev;
		temp=*head;
		prev=temp;

		while(temp!=NULL){
			prev=temp;
			temp=temp->next;
			if (temp->p.x==x && temp->p.y==y){
				prev->next=temp->next;
				free(temp);
				break;
			}
		}

	}

}

void searchd (struct node* head, long double d){

	struct node* temp;
	temp=head;
	ll ctr=0;
	while(temp!=NULL){

		if((temp->p.x)*(temp->p.x)+(temp->p.y)*(temp->p.y)<=(d*d)){
			ctr++;
		}
		temp=temp->next;
	}
	if(ctr>0){
            cout<<ctr<<endl;
	}

	else cout<<"-1"<<endl;

}

long long length (struct node*head){

	struct node* temp;
	temp=head;
	ll l=0;

	while (temp!=NULL){
		l++;
		temp=temp->next;
	}
 return l;
}

void print(struct node *start){
      struct node *temp=start;

      while(temp!=NULL){

            cout<<temp->p.x<<" "<<temp->p.y<<endl;
            temp=temp->next;

      }


}

int main(){

	long long q;

	cin >>q;

	ll f, x, y;
	long double d;

	struct node* head=NULL;


	for(long long i=0; i<q; i++ ){

		cin>>f;
		switch (f){
			case 1: {
				cin>>x>>y;
				addFirst(&head, x ,y);
				break;
			}

			case 2: {
				delFirst(&head);
				break;
			}

			case 3:{
				cin>>x>>y;
				del(&head, x, y);
				break;
			}

			case 4:{
				cin>>d;
				searchd(head, d);
				break;
			}

			case 5: {
				cin>>x>>y;
				ll ct=search(head, x, y);
				if (ct>0){
                              cout<<"True"<<endl;
				}
				else cout<<"False"<<endl;
				break;
			}

			case 6:{
				cout <<length(head)<<endl;
				break;
			}


		}

            //print(head);

	}

	return 0;
}