#include <stdio.h>
 2 #include <stdlib.h>
 3 struct Node
 4 {
 5 int info;
 6 struct Node *next;
 7 };
 8 typedef struct Node ND;
 9 void main()
 10 { ND *tail;
 11 tail=NULL;
 12 int ch,val;
 13 do{printf("\nEnter 1 to insert at begining \nEnter 2 to insert at end\ninsert 3 to insert after\nEnter
4 to insert before\ninsert 5 to delete at begin\nEnter 6 to delete at end\nEnter 7 to display\nEnter your choice
:");
 14 scanf("%d",&ch);
 15 switch(ch)
 16 {
 17 case 1:printf("\nEnter an element to insert :");;
 18 scanf("%d",&val);
 19 insert_begining(&tail,val);
 20 break;
 21 case 2:printf("\nEnter an element to insert :");;
 22 scanf("%d",&val);
 23 insert_end(&tail,val);
 24 break;
 25 case 3:printf("\nEnter a value after which you want to insert");
 26 scanf("%d",&val);
 27 insert_after(&tail,val);
 28 break;
 29 case 4:printf("\nEnter a value before which you want to insert");
 30 scanf("%d",&val);
 31 insert_before(tail,val);
 32 break;
 33 case 5:del_ete_begin(&tail);
 34 break;
 35 case 6:del_ete_end(&tail);
 36 break;
 37 case 8:printf("\nEnter the value before which you want to delete :");
 38 scanf("%d",&val);
 39 del_ete_before(tail,val);
 40 break;
 41 case 9:printf("\nEnter the value after which you want to delete :");
 42 scanf("%d",&val);
 43 del_ete_after(&tail,val);
 44 break;
 45 case 7:display(tail);
 46 }
 47 }while(ch);
 48 }
 49
 50 void insert_begining(ND **ptr,int item)
 51 {
 52 ND *temp;
 53 temp=(ND *)malloc(sizeof(ND));
 54 if(!temp)
 55 {
 56 printf("Insufficient Memory........");
 57 return;
 58 }
 59 temp->info=item;
 60 if(*ptr==NULL)
 61 {
 62 temp->next=temp;
 63 *ptr=temp;
 64 return;
 65 }
 66 temp->next=(*ptr)->next;
 67 (*ptr)->next=temp;
 68 printf("%d",temp->info);
 69 }
 70 void insert_end(ND **ptr,int item)
 71 {
 72 ND *temp;
 73 temp=(ND *)malloc(sizeof(ND));
 74 if(!temp)
 75 {
 76 printf("Insufficient Memory........");
 77 return;
 78 }
 79 temp->info=item;
 80 if(*ptr==NULL)
 81 {
 82 temp->next=temp;
 83 *ptr=temp;
 84 return;
 85 }
 86 temp->next=(*ptr)->next;
 87 (*ptr)->next=temp;
 88 *ptr=temp;
 89 }
 90 void insert_before(ND *ptr,int item)
 91 { int flg;
 92 if(ptr==NULL)
 93 {
 94 printf("Empty Linked List......");
 95 return;
 96 }
 97 ND *current=ptr;
 98
 99 do{if(current->next->info==item)
100 {
101 flg=1;
102 break;
103 }
104 current=current->next;
105 }while(current!=ptr);
106 if(flg==0)
107 {
108 printf("You entered a wrong value.....");
109 return;
110 }
111 ND *temp;
112 temp=(ND *)malloc(sizeof(ND));
113 printf("\nEnter a value you want to Enter : ");
114 scanf("%d",&temp->info);
115 temp->next=current->next;
116 current->next=temp;
117 }
118 void insert_after(ND **ptr,int item)
119 { int flg;
120 if(*ptr==NULL)
121 {
122 printf("Empty Linked List......");
123 return;
124 }
125 ND *current=*ptr;
126
127 do{if(current->info==item)
128 {
129 flg=1;
130 break;
131 }
132 current=current->next;
133 }while(current!=*ptr);
134 if(flg==0)
135 {
136 printf("You entered a wrong value.....");
137 return;
138 }
139 ND *temp;
140 temp=(ND *)malloc(sizeof(ND));
141 printf("\nEnter a value you want to Enter : ");
142 scanf("%d",&temp->info);
143 temp->next=current->next;
144 current->next=temp;
145 if(current==*ptr)
146 *ptr=temp;
147 }
148 void del_ete_begin(ND **ptr)
149 {
150 ND *f=(*ptr)->next;
151 if(f==*ptr)
152 {
153 *ptr=NULL;
154 free(f);
155 return;
156 }
157 (*ptr)->next=f->next;
158 printf("\nDeleted Element is %d",f->info);
159 free(f);
160 }
161 void del_ete_end(ND **ptr)
162 {
163 ND *f=(*ptr)->next,*preptr,*p=*ptr;
164 if(f==*ptr)
165 {
166 *ptr=NULL;
167 free(f);
168 return;
169 }
170 do{
171 preptr=p;
172 p=p->next;
173 }while(p!=*ptr);
174 preptr->next=p->next;
175 *ptr=preptr;
176 printf("\nDeleted Element is %d",p->info);
177 free(p);
178 }
179 void display(ND *p)
180 {
181 ND *current;
182 if(!p)
183 return;
184 current=p->next;
185 do{
186 printf("%d ",current->info);
187 current=current->next;
188 }while(current!=p->next);
189 }
190 void del_ete_before(ND *ptr,int x)
191 {
192 ND *preptr_1,*preptr_2,*p;
193 preptr_1=preptr_2=p=ptr->next;
194
195 do{
196 if(p->info==x)
197 break;
198 preptr_2=preptr_1;
199 preptr_1=p;
200 p=p->next;
201 }while(p!=ptr->next);
202 if(p==ptr->next)
203 {
204 printf("\nInvalid input........");
205 return;
206 }
207 preptr_2->next=p;
208 printf("\nDeleted Element is %d",preptr_1->info);
209
210 if(preptr_1==ptr->next)
211 ptr->next=p;
212 free(preptr_1);
213 }
214 void del_ete_after(ND **ptr,int x)
215 {
216 ND *preptr,*p;
217 preptr=p=(*ptr)->next;
218 printf("Hello");
219 do{
220 if(preptr->info==x)
221 break;
222 preptr=p;
223 p=p->next;
224 }while(p!=(*ptr)->next);
225 if(p==(*ptr)->next)
226 {
227 printf("\nInvalid input........");
228 return;
229 }
230 preptr->next=p->next;
231 printf("\nDeleted Element is %d",p->info);
232 if(p==*ptr)
233 *ptr=preptr;
234 free(p);
235
236 }
