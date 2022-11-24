#include <iostream>
#include <stdio.h>

using namespace std;
 
struct Rcp{
   char tenphim[30];
   char tennguoimua[100];
   char ngaychieu[10];
   char giochieu[5];
   char sohang[10];
   char soghe[10];
   char sorap[10]; 
   float giave;
};
 
struct RCP{
	Rcp r;
	RCP *next;
};
 typedef struct RCP* rcp;
 
struct node{
	RCP *head;
 	RCP *tail;
};
 
rcp makeNode(){
	Rcp r;
	cout << "Nhap thong tin ve :\n";
	cout << "Nhap ten nguoi mua :"; 
	cin >> r.tennguoimua;
	cout << "Nhap ten Phim :"; 
	cin >> r.tenphim;
	cout << "Nhap ngay chieu:";
	cin>>r.ngaychieu;
	cout << "Nhap gio chieu:";
	cin>>r.giochieu;
	cout << "Nhap so hang: \n" ; 
	    cout<<"   _________________________________________________________________________________________   \n "; 
	    cout<<"  |                                                                                         |   \n "; 
	    cout<<"  | H8_______________________________H8           H16_______________________________H16     |   \n ";
	    cout<<"  | H7_______________________________H7           H15_______________________________H15     |   \n ";
		cout<<"  | H6_______________________________H6           H14_______________________________H14     |   \n ";
		cout<<"  | H5_______________________________H5           H13_______________________________H13     |   \n ";
		cout<<"  | H4_______________________________H4           H12_______________________________H12     |   \n ";
		cout<<"  | H3_______________________________H3           H11_______________________________H11     |   \n ";
		cout<<"  | H2_______________________________H2           H10_______________________________H10     |   \n ";
		cout<<"  | H1_______________________________H1           H9________________________________H9      |   \n ";
		cout<<"  |_________________________________________________________________________________________|   \n ";
	cin >>r.sohang;
	cout << "Nhap so ghe: \n";
	    cout<<"   _______________________________________________________________________________________________         \n "; 
	    cout<<"  |                                                                                               |         \n "; 
	    cout<<"  | H8__G57 G58 G59 G60 G61 G62 G63 G64__H8             H16__G57 G58 G59 G60 G61 G62 G63 G64__H16 |         \n ";
	    cout<<"  | H7__G49 G50 G51 G52 G53 G54 G55 G56__H7             H15__G49 G50 G51 G52 G53 G54 G55 G56__H15 |         \n ";
		cout<<"  | H6__G41 G42 G43 G44 G45 G46 G47 G48__H6             H14__G41 G42 G43 G44 G45 G46 G47 G48__H14 |         \n ";
		cout<<"  | H5__G33 G34 G35 G36 G37 G38 G39 G40__H5             H13__G33 G34 G35 G36 G37 G38 G39 G40__H13 |         \n ";
		cout<<"  | H4__G25 G26 G27 G28 G29 G30 G31 G32__H4             H12__G89 G90 G91 G92 G93 G94 G95 G96__H12 |         \n ";
		cout<<"  | H3__G17 G18 G19 G20 G21 G22 G23 G24__H3             H11__G17 G18 G19 G20 G21 G22 G23 G24__H11 |         \n ";
		cout<<"  | H2__G9  G10 G11 G12 G13 G14 G15 G16__H2             H10__G9  G10 G11 G12 G13 G14 G15 G16__H10 |         \n ";
		cout<<"  | H1__G1  G2  G3  G4  G5  G6  G7   G8__H1             H9 __G1  G2  G3  G4  G5  G6  G7   G8__H9  |         \n ";
		cout<<"  |_______________________________________________________________________________________________|         \n ";
	cin >>r.soghe;
	cout << " Rap so :"; 
	cin >> r.sorap;
	cout << " Gia ve :"; 
	cin >> r.giave;
	rcp tmp = new RCP();
	tmp->r = r;
	tmp->next = NULL;
	return tmp;
}

bool empty(rcp a){
	return a == NULL;
}

int Size(rcp a){
	int size = 0;
	while(a != NULL){
		++size;
		a = a->next; 
	}
	return size;
}

void insertFirst(rcp &a){
	rcp tmp = makeNode();
	if(a == NULL){
		a = tmp;
	}
	else{
		tmp->next = a;
		a = tmp;
	}
}

void insertLast(rcp &a){
	rcp tmp = makeNode();
	if(a == NULL){
		a = tmp;
	}
	else{
		rcp p = a;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = tmp;
	}
}

void insertMiddle(rcp &a,int pos){
	int n = Size(a);
	if(pos <= 0 || pos > n + 1){
		cout << "Vi tri chen khong hop le !\n"; 
		return;
	}
	if(pos == 1){
		insertFirst(a);
		 return;
	}
	else if(pos == n + 1 ){
		insertLast(a); 
		return;
	}
	rcp p = a;
	for(int i = 1; i < pos - 1; i++){
		p = p->next;
	}
	rcp tmp = makeNode();
	tmp->next = p->next;
	p->next = tmp;
}

void deleteFirst(rcp &a){
	if(a == NULL) return;
	a = a->next;
}
void deleteLast(rcp &a){
	if(a == NULL) 
	return;
	rcp truoc = NULL, sau = a;
	while(sau->next != NULL){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL){
		a = NULL;
	}
	else{
		truoc->next = NULL;
	}
}

void deleteMiddle(rcp &a, int pos){
	if(pos <=0 || pos > Size(a)) 
	return;
	rcp truoc = NULL, sau = a;
	for(int i = 1; i < pos; i++){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL){
		a = a->next;
	}
	else{
		truoc->next = sau->next;
	}
}
 
void in(Rcp r){
	cout << "--------------------------------\n";
	cout << "Ten Nguoi mua : " <<r.tennguoimua << endl;
	cout << "Ten Phim : " <<r.tenphim <<endl;
	cout << "Ngay chieu :" <<r.ngaychieu <<endl;
	cout << "Gio chieu :" <<r.giochieu<<endl; 
	cout << "So ghe :" << r.soghe <<endl; 
	cout << "So hang: " << r.sohang <<endl; 
	cout << "Rap so :" << r.sorap << endl;
	cout << "Gia ve : " <<r.giave<<"VND" << endl;	
	cout << "--------------------------------\n";
}
 
void prints(rcp a){
	cout << "Danh sach ve :\n";
	while(a != NULL){
		in(a->r);
		a = a->next;
	}
	cout << endl;
}

void deleteList(rcp &a){
	rcp tmp = makeNode();
	while (a!= NULL){
		tmp = a;
		a = tmp->next;
		delete tmp;
	}
}

int main(){
	rcp head = NULL;
	while(1){
		cout << "*************************************\n";
		cout << "*   1. Them ve vao dau danh sach    *\n";
		cout << "*   2. Them ve vao cuoi danh sach   *\n";
		cout << "*   3. Them ve vao giua danh sach   *\n";
		cout << "*   4. Xoa ve o dau                 *\n";
		cout << "*   5. Xoa ve o cuoi                *\n";
		cout << "*   6. Xoa ve o giua                *\n";
		cout << "*   7. Duyet danh sach ve           *\n";
		cout << "*   8. Xoa toan bo danh sach ve     *\n";
		cout << "*   0. Thoat !                      *\n";
		cout << "*************************************\n";
		cout << "NHAP SU LUA CHON :";
		
		int select; cin >> select;
		if(select == 1){
			insertFirst(head);
		}
		else if(select == 2){
			insertLast(head);
		}
		else if(select == 3){
			int pos; 
			cout << "Nhap vi tri can chen :";
			cin >> pos;
			insertMiddle(head, pos);
		}
		else if(select == 4){
			deleteFirst(head);
			cout<< "Da xoa thanh cong\n";
		}
		else if(select == 5){
			deleteLast(head);
			cout<< "Da xoa thanh cong\n";
		}
		else if(select == 6){
			int pos;
			cout << "Nhap vi tri can xoa:";
			cin >> pos;
			deleteMiddle(head, pos);
			cout<< "Da xoa thanh cong\n";
		}
		else if(select == 7){
			prints(head);
		}
		else if(select == 8){
			delete(head);
			cout<< " Toan bo danh sach da xoa thanh cong\n";
		}
		else if(select == 0){
			break;
		}
	}
	return 0;
}
