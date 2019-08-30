#include <iostream>
#include "rsdl.hpp"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const int ArcherCost=70;
const int CanonCost=125;
const int MageCost=90;
const int IcyCost=80;

enum AttackType{
	physical,
	magical,
	none
};

enum enemyType{
	wolf,
	orc,
	demon,
	armored
};

enum towerType{
	archer,
	canon,
	mage,
	icy
};

struct PointType{
	int x,y;
};


struct Player{
	int life=15;
	int money=220;
};
struct ArcherType{
	PointType point;
	int timer=700;
	int speed=700;
	int damage=50;
	AttackType attackType;
};


struct CanonType{
	PointType point;
	int timer=2000;
	int speed=2000;
	int damage=120;
	AttackType attackType;
};

struct MageType{
	PointType point;
	int timer=1500;
	int speed=1500;
	int damage=140;
	AttackType attackType;
};



struct IcyType{
	PointType point;
	int timer=2000;
	int speed=2000;
	int damage=30;
	AttackType attackType;
};

struct WolfType{
	PointType point;
	int timer=0;
	//85
	//11.75
	int speed=60;
	int life=100;
	int value=4;
	int damage=1;
};

struct DemonType{
	PointType point;
	int timer=0;
	//28
	//35.71
	int speed=180;
	int life=400;
	int value=8;
	int damage=3;
};

struct OrcType{
	PointType point;
	int timer=0;
	//42
	//23.81
	int speed=120;
	int life=200;
	int value=5;
	int damage=1;
};

struct ArmoredType{
	PointType point;
	int timer=0;
	//21
	//47.62
	int speed=240;
	int life=450;
	int value=8;
	int damage=3;
};

struct EnemyStruct{
	PointType point={0,0};
	int counterfinal=2;
	bool right=false;
	bool up=false;
	bool left=false;
	bool down=false;

	int counterline=0;
	PointType destination;
	enemyType enemytype;
	WolfType Wolf;
	DemonType Demon;
	OrcType Orc;
	ArmoredType Armored;
	AttackType attackType;
};
struct TowerStruct{
	AttackType attackType;
	PointType point;
	towerType towertype;
	ArcherType Archer;
	CanonType Canon;
	MageType Mage;
	IcyType Icy;
};
//Ball
struct BallStruct{
	PointType point;
	PointType destination;
	AttackType attackType;

};


void goTo(Window& w,EnemyStruct& enemy,PointType newaddress, PointType& address){
	if(newaddress.x!=address.x || newaddress.y!=address.y){
		enemy.up=false;
		enemy.down=false;
		enemy.right=false;
		enemy.left=false;
		if(newaddress.y==address.y){
			if(newaddress.x > address.x){
				if(enemy.enemytype==wolf && enemy.Wolf.timer==enemy.Wolf.speed){
					enemy.Wolf.timer=0;
					address.x = address.x + 5;
				}
				if(enemy.enemytype==demon && enemy.Demon.timer==enemy.Demon.speed){
					enemy.Demon.timer=0;
					address.x = address.x + 5;
				}
				if(enemy.enemytype==orc && enemy.Orc.timer==enemy.Orc.speed){
					enemy.Orc.timer=0;
					address.x = address.x + 5;	
				}
				if(enemy.enemytype==armored && enemy.Armored.timer==enemy.Armored.speed){
					enemy.Armored.timer=0;
					address.x = address.x + 5;
				}
				enemy.right=true;
			}
			else if(newaddress.x < address.x){
				if(enemy.enemytype==wolf && enemy.Wolf.timer==enemy.Wolf.speed){
					enemy.Wolf.timer=0;
					address.x = address.x -5;
				}
				if(enemy.enemytype==demon && enemy.Demon.timer==enemy.Demon.speed){
					enemy.Demon.timer=0;
					address.x = address.x -5;
				}
				if(enemy.enemytype==orc && enemy.Orc.timer==enemy.Orc.speed){
					enemy.Orc.timer=0;
					address.x = address.x -5;
				}
				if(enemy.enemytype==armored && enemy.Armored.timer==enemy.Armored.speed){
					enemy.Armored.timer=0;
					address.x = address.x -5;
				}
				enemy.left=true;
			}
		}
		else if(newaddress.x==address.x){
			if(newaddress.y > address.y){
				if(enemy.enemytype==wolf && enemy.Wolf.timer==enemy.Wolf.speed){
					enemy.Wolf.timer=0;
					address.y =address.y + 5;
				}
				if(enemy.enemytype==demon && enemy.Demon.timer==enemy.Demon.speed){
					enemy.Demon.timer=0;
					address.y =address.y + 5;
				}
				if(enemy.enemytype==orc && enemy.Orc.timer==enemy.Orc.speed){
					enemy.Orc.timer=0;
					address.y =address.y + 5;
				}
				if(enemy.enemytype==armored && enemy.Armored.timer==enemy.Armored.speed){
					enemy.Armored.timer=0;
					address.y =address.y + 5;
				}
				enemy.down=true;
			}
			else if(newaddress.y < address.y){
				if(enemy.enemytype==wolf && enemy.Wolf.timer==enemy.Wolf.speed){
					enemy.Wolf.timer=0;
					address.y =address.y - 5;
				}
				if(enemy.enemytype==demon && enemy.Demon.timer==enemy.Demon.speed){
					enemy.Demon.timer=0;
					address.y =address.y - 5;
				}
				if(enemy.enemytype==orc && enemy.Orc.timer==enemy.Orc.speed){
					enemy.Orc.timer=0;
					address.y =address.y - 5;
				}
				if(enemy.enemytype==armored && enemy.Armored.timer==enemy.Armored.speed){
					enemy.Armored.timer=0;
					address.y =address.y - 5;
				}
				enemy.up=true;
			}
		}
		else if(newaddress.x!=address.x && newaddress.y!=address.y){
			if(newaddress.x > address.x){
				if(enemy.enemytype==wolf && enemy.Wolf.timer==enemy.Wolf.speed){
					enemy.Wolf.timer=0;
					address.x = address.x + 5;
				}
				if(enemy.enemytype==demon && enemy.Demon.timer==enemy.Demon.speed){
					enemy.Demon.timer=0;
					address.x = address.x + 5;
				}
				if(enemy.enemytype==orc && enemy.Orc.timer==enemy.Orc.speed){
					enemy.Orc.timer=0;
					address.x = address.x + 5;
				}
				if(enemy.enemytype==armored && enemy.Armored.timer==enemy.Armored.speed){
					enemy.Armored.timer=0;
					address.x = address.x + 5;
				}
				enemy.right=true;
			}
			else if(newaddress.x < address.x){
				if(enemy.enemytype==wolf && enemy.Wolf.timer==enemy.Wolf.speed){
					enemy.Wolf.timer=0;
					address.x =address.x - 5;
				}
				if(enemy.enemytype==demon && enemy.Demon.timer==enemy.Demon.speed){
					enemy.Demon.timer=0;
					address.x =address.x - 5;
				}
				if(enemy.enemytype==orc && enemy.Orc.timer==enemy.Orc.speed){
					enemy.Orc.timer=0;
					address.x =address.x - 5;
				}
				if(enemy.enemytype==armored && enemy.Armored.timer==enemy.Armored.speed){
					enemy.Armored.timer=0;
					address.x =address.x - 5;
				}
				enemy.left=true;
			}
			
			if(newaddress.y > address.y){
				if(enemy.enemytype==wolf && enemy.Wolf.timer==enemy.Wolf.speed){
					enemy.Wolf.timer=0;
					address.y =address.y + 5;
				}
				if(enemy.enemytype==demon && enemy.Demon.timer==enemy.Demon.speed){
					enemy.Demon.timer=0;
					address.y =address.y + 5;
				}
				if(enemy.enemytype==orc && enemy.Orc.timer==enemy.Orc.speed){
					enemy.Orc.timer=0;
					address.y =address.y + 5;
				}
				if(enemy.enemytype==armored && enemy.Armored.timer==enemy.Armored.speed){
					enemy.Armored.timer=0;
					address.y =address.y + 5;
				}
				enemy.down=true;
			}
			else if(newaddress.y < address.y){
				if(enemy.enemytype==wolf && enemy.Wolf.timer==enemy.Wolf.speed){
					enemy.Wolf.timer=0;
					address.y =address.y - 5;
				}
				if(enemy.enemytype==demon && enemy.Demon.timer==enemy.Demon.speed){
					enemy.Demon.timer=0;
					address.y =address.y - 5;
				}
				if(enemy.enemytype==orc && enemy.Orc.timer==enemy.Orc.speed){
					enemy.Orc.timer=0;
					address.y =address.y - 5;
				}
				if(enemy.enemytype==armored && enemy.Armored.timer==enemy.Armored.speed){
					enemy.Armored.timer=0;
					address.y =address.y - 5;
				}
				enemy.up=true;
			}
		}
	}
}

void goTo(Window& w,BallStruct& ball,PointType newaddress, PointType& address){
	if(newaddress.x!=address.x || newaddress.y!=address.y){
		if(newaddress.y==address.y){
			if(newaddress.x > address.x)
				address.x = address.x + 5;
			else if(newaddress.x < address.x)	
				address.x = address.x - 5;
		}
		else if(newaddress.x==address.x){
			if(newaddress.y > address.y)
				address.y =address.y + 5;
			else if(newaddress.y < address.y)
				address.y =address.y - 5;
		}
		else if(newaddress.x!=address.x && newaddress.y!=address.y){
			if(newaddress.x > address.x)
				address.x = address.x + 5;
			else if(newaddress.x < address.x)
				address.x =address.x - 5;
			if(newaddress.y > address.y)
				address.y =address.y + 5;
			else if(newaddress.y < address.y)
				address.y =address.y - 5;
		}
	}
}

vector<PointType> Level1Points(){
	vector<PointType> level1points;
	PointType Pointtype={720,240};
	level1points.push_back(Pointtype);
	Pointtype={580,265};
	level1points.push_back(Pointtype);
	Pointtype={510,120};
	level1points.push_back(Pointtype);
	Pointtype={425,130};
	level1points.push_back(Pointtype);
	Pointtype={395,240};
	level1points.push_back(Pointtype);
	Pointtype={340,270};
	level1points.push_back(Pointtype);
	Pointtype={235,290};
	level1points.push_back(Pointtype);
	Pointtype={190,370};
	level1points.push_back(Pointtype);
	Pointtype={245,410};
	level1points.push_back(Pointtype);
	Pointtype={385,400};
	level1points.push_back(Pointtype);
	Pointtype={460,415};
	level1points.push_back(Pointtype);
	Pointtype={490,475};
	level1points.push_back(Pointtype);
	Pointtype={450,525};
	level1points.push_back(Pointtype);
	Pointtype={350,560};
	level1points.push_back(Pointtype);
	Pointtype={340,750};
	level1points.push_back(Pointtype);
	return level1points;
}

vector<PointType> Level2Points(){
	vector<PointType> level1points;
	PointType Pointtype={480,25};
	level1points.push_back(Pointtype);
	Pointtype={490,150};
	level1points.push_back(Pointtype);
	Pointtype={240,185};
	level1points.push_back(Pointtype);
	Pointtype={185,275};
	level1points.push_back(Pointtype);
	Pointtype={250,305};
	level1points.push_back(Pointtype);
	Pointtype={535,325};
	level1points.push_back(Pointtype);
	Pointtype={580,405};
	level1points.push_back(Pointtype);
	Pointtype={530,465};
	level1points.push_back(Pointtype);
	Pointtype={285,480};
	level1points.push_back(Pointtype);
	Pointtype={260,585};
	level1points.push_back(Pointtype);
	Pointtype={340,610};
	level1points.push_back(Pointtype);
	Pointtype={485,625};
	level1points.push_back(Pointtype);
	Pointtype={510,685};
	level1points.push_back(Pointtype);
	return level1points;
}

vector<PointType> Level1Towers(){
	vector<PointType> level1points;
	PointType Pointtype={480,215};
	level1points.push_back(Pointtype);
	Pointtype={345,225};
	level1points.push_back(Pointtype);
	Pointtype={300,365};
	level1points.push_back(Pointtype);
	Pointtype={145,345};
	level1points.push_back(Pointtype);
	Pointtype={430,485};
	level1points.push_back(Pointtype);
	Pointtype={355,505};
	level1points.push_back(Pointtype);
	Pointtype={440,620};
	level1points.push_back(Pointtype);
	Pointtype={525,585};
	level1points.push_back(Pointtype);
	return level1points;
}

vector<PointType> Level2Towers(){
	vector<PointType> level1points;
	PointType Pointtype={480,275};
	level1points.push_back(Pointtype);
	Pointtype={390,275};
	level1points.push_back(Pointtype);
	Pointtype={305,270};
	level1points.push_back(Pointtype);
	Pointtype={410,420};
	level1points.push_back(Pointtype);
	Pointtype={505,420};
	level1points.push_back(Pointtype);
	Pointtype={380,565};
	level1points.push_back(Pointtype);
	Pointtype={480,555};
	level1points.push_back(Pointtype);
	Pointtype={595,605};
	level1points.push_back(Pointtype);
	return level1points;
}

long double sTod(char n){
	long double x;
	switch(n){
		case '0':
			x=0;
			break;
		case '1':
			x=1;
			break;
		case '2':
			x=2;
			break;
		case '3':
			x=3;
			break;
		case '4':
			x=4;
			break;
		case '5':
			x=5;
			break;
		case '6':
			x=6;
			break;
		case '7':
			x=7;
			break;
		case '8':
			x=8;
			break;
		case '9':
			x=9;
			break;
	}
	return x;
}

vector<long double> GetTime(vector<string> levelinfo){
	vector<long double> time;
	long double Time=0;
	bool go=true;
	for(int i=0;i<levelinfo.size();i++){
		Time=0;
		for(int j=0;j<levelinfo[i].size();j++){
			if(levelinfo[i][j]!=',' && go){
				Time*=10;
				Time+= sTod(levelinfo[i][j]);
			}
			else
				go=false;
		}
		go=true;
		time.push_back(Time);
	}
	return time;
}

vector<string> EnemyMap(vector<string> levelinfo){
	bool aftertime=false;
	vector<string> enemymap;
	for(int i=0;i<levelinfo.size();i++){
		string row;
		aftertime=false;
		for(int j=0;j<levelinfo[i].size();j++){
			if(levelinfo[i][j]==',')
				aftertime=true;
			else if(aftertime){
				row.push_back(levelinfo[i][j]);
			}
		}
		enemymap.push_back(row);
	}
	return enemymap;
}

bool EndOfGame(Player player,vector<EnemyStruct> allenemys,int level,long double time){
	if(player.life==0||(level==1 && time>101000 && allenemys.size()==0)||(level==2 && time>112000 && allenemys.size()==0))
		return true;
	else
		return false;
}

bool TowerArea(TowerStruct tower,EnemyStruct enemy){
	if(85*85<(tower.point.x - enemy.point.x)*(tower.point.x - enemy.point.x)+(tower.point.y - enemy.point.y)*(tower.point.y - enemy.point.y))
		return false;
	else
		return true;
}
void UpdateScreen(Window& w,vector<EnemyStruct> allenemys,vector<TowerStruct> alltower,vector<BallStruct> allball,int level){
	switch(level){
		case 1:
			w.draw_png("./assets/levels/1/level1-map.png",0,0,800,800);
			break;
		case 2:
			w.draw_png("./assets/levels/2/level2-map.png",0,0,800,800);
			break;
	}
	for(int i=0;i<alltower.size();i++){
		if(alltower[i].towertype==mage)
			w.draw_png("./assets/towers/mage.png",alltower[i].point.x,alltower[i].point.y,100,70);
		else if(alltower[i].towertype==canon)
			w.draw_png("./assets/towers/canon.png",alltower[i].point.x,alltower[i].point.y,100,70);
		else if(alltower[i].towertype==archer)
			w.draw_png("./assets/towers/archer.png",alltower[i].point.x,alltower[i].point.y,100,70);
		else if(alltower[i].towertype==icy)
			w.draw_png("./assets/towers/icy.png",alltower[i].point.x,alltower[i].point.y,100,70);
	}
	for(int i=0;i<allenemys.size();i++){
		if(allenemys[i].left==true){
			if(allenemys[i].enemytype==orc)
				w.draw_png("./assets/enemies/orc/left.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
			if(allenemys[i].enemytype==demon)
				w.draw_png("./assets/enemies/demon/left.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
			if(allenemys[i].enemytype==armored)
				w.draw_png("./assets/enemies/armored/left.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
			if(allenemys[i].enemytype==wolf)
				w.draw_png("./assets/enemies/wolf/left.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
		}
		else if(allenemys[i].right==true){
			if(allenemys[i].enemytype==orc)
				w.draw_png("./assets/enemies/orc/right.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
			if(allenemys[i].enemytype==demon)
				w.draw_png("./assets/enemies/demon/right.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
			if(allenemys[i].enemytype==armored)
				w.draw_png("./assets/enemies/armored/right.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
			if(allenemys[i].enemytype==wolf)
				w.draw_png("./assets/enemies/wolf/right.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
		}
		else if(allenemys[i].up==true){
			if(allenemys[i].enemytype==orc)
				w.draw_png("./assets/enemies/orc/back.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
			if(allenemys[i].enemytype==demon)
				w.draw_png("./assets/enemies/demon/back.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
			if(allenemys[i].enemytype==armored)
				w.draw_png("./assets/enemies/armored/back.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
			if(allenemys[i].enemytype==wolf)
				w.draw_png("./assets/enemies/wolf/back.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
		}
		else if(allenemys[i].down==true){
			if(allenemys[i].enemytype==orc)
				w.draw_png("./assets/enemies/orc/front.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
			if(allenemys[i].enemytype==demon)
				w.draw_png("./assets/enemies/demon/front.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
			if(allenemys[i].enemytype==armored)
				w.draw_png("./assets/enemies/armored/front.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
			if(allenemys[i].enemytype==wolf)
				w.draw_png("./assets/enemies/wolf/front.png",allenemys[i].point.x,allenemys[i].point.y,50,40);
		}
	}
	for(int i=0;i<allball.size();i++){
		//cout<<"byeeeeeeeeeeeeee"<<endl<<endl;
		w.draw_rect(allball[i].point.x,allball[i].point.y,40,40,RED);
	}
	w.update_screen();

}



int main(){
	cout<<"which level do you want to lunch?"<<endl;
	int level;

	Event event;
	Window w(800,800,"Kingdom Rush");
	w.draw_png("bg.png",0,0,800,800);
	w.update_screen();
	w.clear();
	while(cin>>level){
		bool Quit=true;
		ifstream mapfile;
		Player player;
		int i=0,counterline=0;
		long double time=0;
		string line;
		PointType point={0,0};
		vector<PointType> levelpoints,leveltowers;
		vector<string> levelinfo,enemymap;
		vector<long double> Time;
		vector<EnemyStruct> allenemys;
		vector<TowerStruct> alltower;
		vector<BallStruct> allball;
		switch(level){
			case 1:
				mapfile.open("level1.txt");
				while(getline(mapfile,line)){
					levelinfo.push_back(line);
				}
				levelpoints=Level1Points();
				Time=GetTime(levelinfo);
				enemymap=EnemyMap(levelinfo);
				w.draw_png("./assets/levels/1/level1-map.png",0,0,800,800);
				leveltowers=Level1Towers();
				break;
			case 2:
				mapfile.open("level2.txt");
				while(getline(mapfile,line)){
					levelinfo.push_back(line);
				}
				Time=GetTime(levelinfo);
				levelpoints=Level2Points();
				enemymap=EnemyMap(levelinfo);
				w.draw_png("./assets/levels/2/level2-map.png",0,0,800,800);
				leveltowers=Level2Towers();
				break;
		}
		mapfile.close();
		w.update_screen();

		do{
			//cout<<time<<" "<<Time[i]<<endl;
			bool maketower=false;
			if(time==Time[i]){
				for(int j=0;j<enemymap[i].size();j++){
					if(enemymap[i][j]=='a'){
						EnemyStruct Armored;
						allenemys.push_back(Armored);
						allenemys[allenemys.size()-1].attackType=physical;
						allenemys[allenemys.size()-1].enemytype=armored;
					}
					else if(enemymap[i][j]=='o'){
						EnemyStruct Orc;
						allenemys.push_back(Orc);
						allenemys[allenemys.size()-1].attackType=none;
						allenemys[allenemys.size()-1].enemytype=orc;
					}
					else if(enemymap[i][j]=='d'){
						EnemyStruct Demon;
						allenemys.push_back(Demon);
						allenemys[allenemys.size()-1].attackType=magical;
						allenemys[allenemys.size()-1].enemytype=demon;
					}
					else if(enemymap[i][j]=='w'){
						EnemyStruct Wolf;
						allenemys.push_back(Wolf);
						allenemys[allenemys.size()-1].attackType=none;
						allenemys[allenemys.size()-1].enemytype=wolf;
					}

					allenemys[allenemys.size()-1].destination=levelpoints[1];
					allenemys[allenemys.size()-1].point=levelpoints[0];
					if(counterline==0){
						allenemys[allenemys.size()-1].point.y+=10;
						counterline++;
					}
					else if(counterline==1){
						allenemys[allenemys.size()-1].point.y+=20;
						counterline++;
					}
					else if(counterline==2){
						allenemys[allenemys.size()-1].point.y+=30;
						counterline++;
					}
					else if(counterline==3){
						allenemys[allenemys.size()-1].point.x+=20;
						counterline++;
					}
					else if(counterline==4){
						allenemys[allenemys.size()-1].point.y+=10;
						allenemys[allenemys.size()-1].point.x+=20;
						counterline++;
					}
					else if(counterline==5){
						allenemys[allenemys.size()-1].point.y+=20;
						allenemys[allenemys.size()-1].point.x+=20;
						counterline=0;
					}
				}
				counterline=0;
				i++;
			}
			for(int j=0;j<allenemys.size();j++){
				if(allenemys[j].enemytype==wolf)
					allenemys[j].Wolf.timer+=10;
				if(allenemys[j].enemytype==demon)
					allenemys[j].Demon.timer+=10;
				if(allenemys[j].enemytype==orc)
					allenemys[j].Orc.timer+=10;
				if(allenemys[j].enemytype==armored)
					allenemys[j].Armored.timer+=10;
				if(allenemys[j].destination.x!=allenemys[j].point.x || allenemys[j].destination.y!=allenemys[j].point.y){
					goTo(w,allenemys[j],allenemys[j].destination,allenemys[j].point);
				}
				else if(allenemys[j].counterfinal!=levelpoints.size()-1){
					if(allenemys[j].destination.x==allenemys[j].point.x && allenemys[j].destination.y==allenemys[j].point.y){
						allenemys[j].destination=levelpoints[allenemys[j].counterfinal];
						allenemys[j].counterfinal++;
						goTo(w,allenemys[j],allenemys[j].destination,allenemys[j].point);
					}
				}
				else if(allenemys[j].counterfinal==levelpoints.size()-1){
					if(allenemys[j].enemytype==wolf)
						player.life=player.life - allenemys[j].Wolf.damage;
					if(allenemys[j].enemytype==orc)
						player.life=player.life - allenemys[j].Orc.damage;
					if(allenemys[j].enemytype==demon)
						player.life=player.life - allenemys[j].Demon.damage;
					if(allenemys[j].enemytype==armored)
						player.life=player.life - allenemys[j].Armored.damage;
					allenemys.erase(allenemys.begin()+j);
				}
			}
			event=w.pollForEvent();
			if (event.type()==LCLICK){
				point.x=event.mouseX();
				point.y=event.mouseY();
			}
			for(int j=0;j<leveltowers.size();j++){
				if( point.x < (leveltowers[j].x + 50) && point.x > (leveltowers[j].x - 50)  && point.y < (leveltowers[j].y + 50) && point.y > (leveltowers[j].y - 50)){
					point.x = leveltowers[j].x - 45;
					point.y = leveltowers[j].y - 40;
					maketower=true;
				}
			}
			if(event.type()==KEY_PRESS && maketower){
				switch(event.pressedKey()){
					case 'a':
						if(player.money>=ArcherCost)
						{
							TowerStruct Archer;
							alltower.push_back(Archer);
							alltower[alltower.size()-1].point=point;
							alltower[alltower.size()-1].towertype=archer;
							alltower[alltower.size()-1].attackType=physical;
							player.money=player.money - ArcherCost;
						}
						break;
					case 'c':
						if(player.money>=CanonCost)
						{
							TowerStruct Canon;
							alltower.push_back(Canon);
							alltower[alltower.size()-1].point=point;
							alltower[alltower.size()-1].towertype=canon;
							alltower[alltower.size()-1].attackType=physical;
							player.money=player.money- CanonCost;
						}
						break;
					case 'm':
						if(player.money>=MageCost)
						{
							TowerStruct Mage;
							alltower.push_back(Mage);
							alltower[alltower.size()-1].point=point;
							alltower[alltower.size()-1].towertype=mage;
							alltower[alltower.size()-1].attackType=magical;
							player.money=player.money - MageCost;
						}
						break;
					case 'i':
						if(player.money>=IcyCost)
						{
							TowerStruct Icy;
							alltower.push_back(Icy);
							alltower[alltower.size()-1].point=point;
							alltower[alltower.size()-1].towertype=icy;
							alltower[alltower.size()-1].attackType=magical;
							player.money=player.money - IcyCost;
						}
						break;
				}
			}
			
			for(int h=0;h<alltower.size();h++){
				for(int j=0;j<allenemys.size();j++){

					if(alltower[h].towertype==archer){
						if(TowerArea(alltower[h],allenemys[j])){

							if(alltower[h].Archer.speed <= alltower[h].Archer.timer){
								BallStruct Ball;
								allball.push_back(Ball);
								allball[allball.size() - 1].attackType=alltower[h].attackType;
								allball[allball.size() - 1].point=alltower[h].point;
								alltower[h].Archer.timer = 0;
							}
							for(int f=0;f<allball.size();f++){
								
								if(allenemys[j].point.x == allball[f].point.x && allenemys[j].point.y == allball[f].point.y){
									if(allball[f].attackType==allenemys[j].attackType){
										if(allenemys[j].enemytype==wolf)
											allenemys[j].Wolf.life =allenemys[j].Wolf.life - (alltower[h].Archer.damage/2);
										else if(allenemys[j].enemytype==orc)
											allenemys[j].Orc.life =allenemys[j].Orc.life - (alltower[h].Archer.damage/2);
										else if(allenemys[j].enemytype==armored)
											allenemys[j].Armored.life =allenemys[j].Armored.life - (alltower[h].Archer.damage/2);
										else if(allenemys[j].enemytype==demon)
											allenemys[j].Demon.life =allenemys[j].Demon.life - (alltower[h].Archer.damage/2);
									}
									else{
										if(allenemys[j].enemytype==wolf)
											allenemys[j].Wolf.life =allenemys[j].Wolf.life - alltower[h].Archer.damage;
										else if(allenemys[j].enemytype==orc)
											allenemys[j].Orc.life =allenemys[j].Orc.life - alltower[h].Archer.damage;
										else if(allenemys[j].enemytype==armored)
											allenemys[j].Armored.life =allenemys[j].Armored.life - alltower[h].Archer.damage;
										else if(allenemys[j].enemytype==demon)
											allenemys[j].Demon.life =allenemys[j].Demon.life - alltower[h].Archer.damage;
									}
									allball.erase(allball.begin()+f);
								}
							}		
						}
					}
					if(alltower[h].towertype==mage){
						if(TowerArea(alltower[h],allenemys[j])){
							if(alltower[h].Mage.speed <= alltower[h].Mage.timer){
								BallStruct Ball;
								allball.push_back(Ball);
								allball[allball.size() - 1].attackType=alltower[h].attackType;
								allball[allball.size() - 1].point=alltower[h].point;
								alltower[h].Mage.timer=0;
							}
							for(int f=0;f<allball.size();f++){
								if(allenemys[j].point.x==allball[f].point.x && allenemys[j].point.y==allball[f].point.y){
									if(allball[f].attackType==allenemys[j].attackType){
										if(allenemys[j].enemytype==wolf)
											allenemys[j].Wolf.life =allenemys[j].Wolf.life - (alltower[h].Mage.damage/2);
										else if(allenemys[j].enemytype==orc)
											allenemys[j].Orc.life =allenemys[j].Orc.life - (alltower[h].Mage.damage/2);
										else if(allenemys[j].enemytype==armored)
											allenemys[j].Armored.life =allenemys[j].Armored.life - (alltower[h].Mage.damage/2);
										else if(allenemys[j].enemytype==demon)
											allenemys[j].Demon.life =allenemys[j].Demon.life - (alltower[h].Mage.damage/2);						
									}
									else{
										if(allenemys[j].enemytype==wolf)
											allenemys[j].Wolf.life =allenemys[j].Wolf.life - alltower[h].Mage.damage;
										else if(allenemys[j].enemytype==orc)
											allenemys[j].Orc.life =allenemys[j].Orc.life - alltower[h].Mage.damage;
										else if(allenemys[j].enemytype==armored)
											allenemys[j].Armored.life =allenemys[j].Armored.life - alltower[h].Mage.damage;
										else if(allenemys[j].enemytype==demon)
											allenemys[j].Demon.life =allenemys[j].Demon.life - alltower[h].Mage.damage;
									}
									allball.erase(allball.begin()+f);
								}
							}		
						}
					}
					if(alltower[h].towertype==canon){
						if(TowerArea(alltower[h],allenemys[j])){
							if(alltower[h].Canon.speed<=alltower[h].Canon.timer){
								BallStruct Ball;
								allball.push_back(Ball);
								allball[allball.size()-1].attackType=alltower[h].attackType;
								allball[allball.size()-1].point=alltower[h].point;
								alltower[h].Canon.timer=0;
							}
							for(int f=0;f<allball.size();f++){
								if(allenemys[j].point.x==allball[f].point.x && allenemys[j].point.y==allball[f].point.y){
									if(allball[f].attackType==allenemys[j].attackType){
										for(int g=0;g<allenemys.size();g++)
											if(50*50>(allball[f].point.x - allenemys[g].point.x)*(allball[f].point.x - allenemys[g].point.x)+(allball[f].point.y - allenemys[g].point.y)*(allball[f].point.y - allenemys[g].point.y)){
												if(allenemys[j].enemytype==wolf)
													allenemys[j].Wolf.life =allenemys[j].Wolf.life - (alltower[h].Canon.damage/2);
												else if(allenemys[j].enemytype==orc)
													allenemys[j].Orc.life =allenemys[j].Orc.life - (alltower[h].Canon.damage/2);
												else if(allenemys[j].enemytype==armored)
													allenemys[j].Armored.life =allenemys[j].Armored.life - (alltower[h].Canon.damage/2);
												else if(allenemys[j].enemytype==demon)
													allenemys[j].Demon.life =allenemys[j].Demon.life - (alltower[h].Canon.damage/2);									
											}
									}
									else{
										for(int g=0;g<allenemys.size();g++)
											if(50*50>(allball[f].point.x - allenemys[g].point.x)*(allball[f].point.x - allenemys[g].point.x)+(allball[f].point.y - allenemys[g].point.y)*(allball[f].point.y - allenemys[g].point.y)){
												if(allenemys[j].enemytype==wolf)
													allenemys[j].Wolf.life =allenemys[j].Wolf.life - alltower[h].Canon.damage;
												else if(allenemys[j].enemytype==orc)
													allenemys[j].Orc.life =allenemys[j].Orc.life - alltower[h].Canon.damage;
												else if(allenemys[j].enemytype==armored)
													allenemys[j].Armored.life =allenemys[j].Armored.life - alltower[h].Canon.damage;
												else if(allenemys[j].enemytype==demon)
													allenemys[j].Demon.life =allenemys[j].Demon.life - alltower[h].Canon.damage;
											}
									}
									allball.erase(allball.begin()+f);
								}
							}		
						}
					}
					if(alltower[h].towertype==icy){
						if(TowerArea(alltower[h],allenemys[j])){
							if(alltower[h].Canon.speed<=alltower[h].Icy.timer){
								BallStruct Ball;
								allball.push_back(Ball);
								allball[allball.size()-1].attackType=alltower[h].attackType;
								allball[allball.size()-1].point=alltower[h].point;
								alltower[h].Icy.timer=0;
							}
							for(int f=0;f<allball.size();f++){
								if(allenemys[j].point.x==allball[f].point.x && allenemys[j].point.y==allball[f].point.y){
									if(allball[f].attackType==allenemys[j].attackType){
										//dorost kardan ice kardan doshmanaye dar mahdode
										for(int g=0;g<allenemys.size();g++)
											if(50*50>(allball[f].point.x - allenemys[g].point.x)*(allball[f].point.x - allenemys[g].point.x)+(allball[f].point.y - allenemys[g].point.y)*(allball[f].point.y - allenemys[g].point.y)){
												if(allenemys[j].enemytype==wolf)
													allenemys[j].Wolf.life =allenemys[j].Wolf.life - (alltower[h].Icy.damage/2);
												else if(allenemys[j].enemytype==orc)
													allenemys[j].Orc.life =allenemys[j].Orc.life - (alltower[h].Icy.damage/2);
												else if(allenemys[j].enemytype==armored)
													allenemys[j].Armored.life =allenemys[j].Armored.life - (alltower[h].Icy.damage/2);
												else if(allenemys[j].enemytype==demon)
													allenemys[j].Demon.life =allenemys[j].Demon.life - (alltower[h].Icy.damage/2);									
											}
									}
									else{
									//dorost kardan ice kardan doshmanaye dar mahdode
										for(int g=0;g<allenemys.size();g++)
											if(50*50>(allball[f].point.x - allenemys[g].point.x)*(allball[f].point.x - allenemys[g].point.x)+(allball[f].point.y - allenemys[g].point.y)*(allball[f].point.y - allenemys[g].point.y)){
												if(allenemys[j].enemytype==wolf)
													allenemys[j].Wolf.life =allenemys[j].Wolf.life - alltower[h].Icy.damage;
												else if(allenemys[j].enemytype==orc)
													allenemys[j].Orc.life =allenemys[j].Orc.life - alltower[h].Icy.damage;
												else if(allenemys[j].enemytype==armored)
													allenemys[j].Armored.life =allenemys[j].Armored.life - alltower[h].Icy.damage;
												else if(allenemys[j].enemytype==demon)
													allenemys[j].Demon.life =allenemys[j].Demon.life - alltower[h].Icy.damage;									
											}
									}
									allball.erase(allball.begin()+f);
								}
							}		
						}
					}
					alltower[h].Archer.timer+=10;
					alltower[h].Canon.timer+=10;
					alltower[h].Mage.timer+=10;
					alltower[h].Icy.timer+=10;
				for(int f=0;f<allball.size();f++){
					allball[f].destination=allenemys[j].point;
					goTo(w,allball[f],allball[f].destination,allball[f].point);	
				}
				
				if(allenemys[j].enemytype==wolf)
					if(allenemys[j].Wolf.life <=0){
						player.money+=allenemys[j].Wolf.value;
						allenemys.erase(allenemys.begin()+j);
					}
				else if(allenemys[j].enemytype==orc)
					if(allenemys[j].Orc.life <=0){
						player.money+=allenemys[j].Orc.value;
						allenemys.erase(allenemys.begin()+j);
					}
				else if(allenemys[j].enemytype==armored)
					if(allenemys[j].Armored.life <=0){
						player.money+=allenemys[j].Armored.value;
						allenemys.erase(allenemys.begin()+j);
					}
				else if(allenemys[j].enemytype==demon)
					if(allenemys[j].Demon.life <=0){
						player.money+=allenemys[j].Demon.value;
						allenemys.erase(allenemys.begin()+j);			
					}
				}
			}
			if(event.type()==QUIT){
				Quit=false;
			}
			time+=10;
			Delay(10);
			UpdateScreen(w,allenemys,alltower,allball,level);
		}while(!EndOfGame(player,allenemys,level,time) && Quit);
		Quit=true;
		if(player.life==0)
			cout<<"You Lose!!!"<<endl;
		if(allenemys.size()==0)
			cout<<"You Win!!!"<<endl;
		w.clear();
		w.update_screen();
		cout<<"which level do you want to lunch?"<<endl;		
	}
	return 0;
}