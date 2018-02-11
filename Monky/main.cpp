#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h> 
#include <stdio.h> 
#include <stdlib.h> 

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	string opcja_menu;
	int ruchy = 20;
	int hax = 0;
	
menu:
	system("cls");
	cout<<"\t"<<"+-----+"<<endl;
	cout<<"\t"<<"|Start|"<<endl;
	cout<<"\t"<<"+-----+"<<endl;
	cout<<"\t"<<"|Opcje|"<<endl;
	cout<<"\t"<<"+-----+"<<endl;
	cout<<"\t"<<"|Wyjdz|"<<endl;
	cout<<"\t"<<"+-----+"<<endl;	
	cout<<"\t";
	cin>>opcja_menu;
		
if ( opcja_menu != "Start" and opcja_menu != "Opcje" and opcja_menu != "Wyjdz" and opcja_menu != "start" and opcja_menu != "opcje" and opcja_menu != "wyjdz" )  { goto menu; }
	
if ( opcja_menu == "Start" or opcja_menu == "start" )
{
start:
	int przejscie = 0;
	int przejscia = 0;
	int poziom = 1;
	
	system("cls");
	
	string ruch_gracz;
	string znak_podloga = ".";
	string znak_gracz = "@";
	
	string plansza[8][7];
	for (int i1 = 0; i1 < 8; i1++ )
		{
			for (int i2 = 0; i2 < 7; i2++)
				{
					plansza[i1][i2] = "~";
				}
		}
		
		plansza[0][0] = "+";
		plansza[0][6] = "+";
		plansza[7][0] = "+";
		plansza[7][6] = "+";
		plansza[7][3] = "-";	

	string plansza_wyglad[8][7] 
		{
			
			{ "+", "-", "-", "-", "-", "-", "+" },
			{ "|", ".", ".", ".", ".", ".", "|" },
			{ "|", ".", ".", ".", ".", ".", "|" },
			{ "|", ".", ".", ".", ".", ".", "|" },
			{ "|", ".", ".", ".", ".", ".", "|" },
			{ "|", ".", ".", ".", ".", ".", "|" },		
			{ "|", ".", ".", ".", ".", ".", "|" },
			{ "+", "-", "-", "-", "-", "-", "+" }
			
		};
		
	while(true)	//gra sie toczy
	{
		int ruch_w = 6;
		int ruch_h = 3;
		plansza[ruch_w][ruch_h] = "@";
		
		int plansza_drzwi;
		int plansza_drzwi_r;
		
		plansza_drzwi_r = 1 + (int) (4.0 * (rand() / (RAND_MAX + 1.0))); // 1-gora 2-prawo 3-dol 4-lewo
		
		if (plansza_drzwi_r == 1 ) { plansza_drzwi = 1 + ( int ) ( 5.0 * ( rand() / ( RAND_MAX + 1.0 ) ) ); } //1-5 gora 
		if (plansza_drzwi_r == 2 ) { plansza_drzwi = 1 + ( int ) ( 6.0 * ( rand() / ( RAND_MAX + 1.0 ) ) ); } //1-6 prawo 	
		if (plansza_drzwi_r == 3 ) { los3b: plansza_drzwi = 1 + ( int ) ( 5.0 * ( rand() / ( RAND_MAX + 1.0 ) ) ); if ( plansza_drzwi == 3 ) { goto los3b; } } //1-5 bez 3 dol
		if (plansza_drzwi_r == 4 ) { plansza_drzwi = 1 + ( int ) ( 6.0 * ( rand() / ( RAND_MAX + 1.0 ) ) ); } //1-6 lewo
		
		int banan_off;
		
		if ( poziom%2 == 1 and ruchy < 10 and przejscia > 1 ) { plansza[3][3] = "("; banan_off = 0; }else { banan_off = 1; }
		
	przejscie = 0;
		 
	while( przejscie == 0 ) //przejscia
	{	
	
	if (hax == 1)
		{
			if ( ruch_gracz == "odnowa" )     { goto start; }
			if ( ruch_gracz == "ruch+1" )     { ruchy += 1; } 
			if ( ruch_gracz == "ruch+10" )    { ruchy += 10; } 
			if ( ruch_gracz == "ruch+100" )   { ruchy += 100; } 
			if ( ruch_gracz == "poziom+1" )   { poziom += 1; } 
			if ( ruch_gracz == "next" ) 	  { przejscia += 1; przejscie = 1;} 
		}
		if ( ruch_gracz == "menu" ) { goto menu; } 
	    
	if ( ruch_w == 3 and ruch_h == 3 and banan_off == 0) { ruchy += 3; banan_off = 1;}
	
	cout<<"\t"<<"+-----+"<<endl;
	
	if ( poziom < 10 )  				{ cout<<"\t"<<"| "<<"00"<<poziom<<" |"<<endl; }
	if ( poziom > 9 and poziom < 100 ) 	{ cout<<"\t"<<"| "<<"0"<<poziom<<" |"<<endl; }
	if ( poziom > 99 )  				{ cout<<"\t"<<"| "<<poziom<<" |"<<endl; }	
	
	cout<<"\t"<<"+-----+"<<endl;
	
	if ( przejscia < 10 )  					{ cout<<"\t"<<"| "<<"00"<<przejscia<<" |"<<endl; }
	if ( przejscia > 9 and poziom < 100 ) 	{ cout<<"\t"<<"| "<<"0"<<przejscia<<" |"<<endl; }
	if ( przejscia > 99 )  					{ cout<<"\t"<<"| "<<przejscia<<" |"<<endl; }
	
	cout<<"\t"<<"+-----+"<<endl;
	cout<<"\t"<<"|     |"<<endl;	
					
	for (int i=0; i<8; i++)
		{
			cout<<"\t";
			for (int j=0; j<7; j++)
				{
					
					cout<<plansza[i][j];
					
				}
			cout<<endl;
		}
		
	if ( ruchy < 10 )  					{ cout<<"\t"<<"| "<<"00"<<ruchy<<" |"<<endl; }
	if ( ruchy > 9 and ruchy < 100 ) 	{ cout<<"\t"<<"| "<<"0"<<ruchy<<" |"<<endl; }
	if ( ruchy > 99 )  					{ cout<<"\t"<<"| "<<ruchy<<" |"<<endl; }
	
		cout<<"\t"<<"+-----+"<<endl;
		cout<<"\t|  "<<"^"<<"  |"<<endl;
		cout<<"\t|  "<<"w"<<"  |"<<endl;

		cout<<"\t|"<<"<a"<<"+"<<"d>"<<"|"<<endl;

		cout<<"\t|  "<<"s"<<"  |"<<endl;
		cout<<"\t|  "<<"V"<<"  |"<<endl;
		cout<<"\t"<<"+-----+"<<endl;	
		
		cout<<"        "<<"Ruch: ";
		cin>>ruch_gracz;
		if (ruch_gracz == "nowa") { goto start; }
		
		if ( ruch_gracz == "w"  && ruchy > 0 ) 
			{  
				if ( ruch_w > 1 )
					{
						plansza[ruch_w][ruch_h] = znak_podloga;
						ruch_w -= 1; 
						plansza[ruch_w][ruch_h] = znak_gracz;
						ruchy -= 1;
					}
			}
		
		if ( ruch_gracz == "s" && ruchy > 0 ) 
			{  
				if( ruch_w < 6 )
					{
						plansza[ruch_w][ruch_h] = znak_podloga;
						ruch_w += 1; 
						plansza[ruch_w][ruch_h] = znak_gracz;	
						ruchy -= 1;
					}
				
			}
				
		if ( ruch_gracz == "a" && ruchy > 0 ) 
			{  
				if( ruch_h > 1 )
					{
						plansza[ruch_w][ruch_h] = znak_podloga;
						ruch_h -= 1; 
						plansza[ruch_w][ruch_h] = znak_gracz;
						ruchy -= 1;
					}
				
			}
		
		if ( ruch_gracz == "d" && ruchy > 0 ) 
			{  
				if( ruch_h < 5 )
					{
						plansza[ruch_w][ruch_h] = znak_podloga;
						ruch_h += 1; 
						plansza[ruch_w][ruch_h] = znak_gracz;
						ruchy -= 1;	
					}
				
			}	
				
	for ( int i3 = 1; i3 < 6; i3++ ) //dolna warstwa
		{
			if ( ruch_w == 6 and ruch_h == i3 ) { if ( plansza_drzwi_r == 3 ) { if (plansza_drzwi == i3) { plansza[7][i3] = " "; if ( ruch_gracz == "e" ) { przejscia += 1; przejscie = 1; ruchy += 5; } }else plansza[7][i3] = "-"; }else plansza[7][i3] = "-"; }
		}

	for ( int i3 = 1; i3 < 6; i3++ ) //gorna warstwa
		{
			if ( ruch_w == 1 and ruch_h == i3 ) { if ( plansza_drzwi_r == 1 ) { if (plansza_drzwi == i3) { plansza[0][i3] = " "; if ( ruch_gracz == "e" ) { przejscia += 1; przejscie = 1; ruchy += 5; } }else plansza[0][i3] = "-"; }else plansza[0][i3] = "-"; }
		}
		
	for ( int i3 = 1; i3 < 7; i3++ ) //lewa warstwa
		{
			if ( ruch_w == i3 and ruch_h == 1 ) {  if ( plansza_drzwi_r == 4 ) { if (plansza_drzwi == i3) { plansza[i3][0] = " "; if ( ruch_gracz == "e" ) { przejscia += 1; przejscie = 1; ruchy += 5; } }else plansza[i3][0] = "|"; }else plansza[i3][0] = "|"; } 
		}
		
	for ( int i3 = 1; i3 < 7; i3++ )//prawa warstwa
		{
			if ( ruch_w == i3 and ruch_h == 5 ) { if ( plansza_drzwi_r == 2 ) { if (plansza_drzwi == i3) { plansza[i3][6] = " "; if ( ruch_gracz == "e" ) { przejscia += 1; przejscie = 1; ruchy += 5; } }else plansza[i3][6] = "|"; }else plansza[i3][6] = "|"; }
		}
		
					
		system("cls");
	
	}
	
	if ( poziom == przejscia ) { poziom += 1; przejscia = 0; ruchy += 10; } // ukoncczony poziom
	
	for (int i1 = 0; i1 < 8; i1++ )
		{
			for (int i2 = 0; i2 < 7; i2++)
				{
					plansza[i1][i2] = "~";
				}
		}
		
		plansza[0][0] = "+";
		plansza[0][6] = "+";
		plansza[7][0] = "+";
		plansza[7][6] = "+";	
		plansza[7][3] = "-";
		
	
	}//petla gra
	
}//if opcja 1

int edytuj_opcje = 0;

if (opcja_menu == "opcje" or opcja_menu == "Opcje")
{
	
while(edytuj_opcje != 3)
{

	
	opcje:
		
		system("cls");
		cout<<"\t"<<"1.Ilosc ruchow = "<<ruchy<<endl;
		cout<<"\t"<<"2.HAX = "<<hax<<endl;
		cout<<"\t"<<"3.Menu"<<endl;	
		cout<<endl<<"Edytuj opcje: ";
		cin>>edytuj_opcje;

		if (edytuj_opcje == 1) 
			{
				cout<<"Zmien ilosc ruchow na: ";
				cin>>ruchy;
			}
			
		if (edytuj_opcje == 2) 
			{
				cout<<"Zmien wartoœæ HAX na: ";
				cin>>hax;
			}
		if (edytuj_opcje == 3) 
			{
				goto menu;
			}
					
	}//if opcja 2
}

if ( opcja_menu == "Wyjdz" or opcja_menu == "wyjdz" )
	{
		cout<<"\t"<<"Dziêki za wspolny czas! :3"<<endl;
		return 0;
	}//if opcja 3
	
}
