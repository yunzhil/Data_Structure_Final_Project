#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;
#define Linelength 5
#define Citylength 4
#define MAXLINE 10
#define MAXNUMBER 25
#define OK 1;
#define False -1;
#define MAXPRICE 2000000.0
#define MAXVERTEX 25
#define INFTY 2147483647	//???????

typedef struct Line {
	string Linename;//[Linelength];//?г???
	string src;// [Citylength];//????
	string dest;// [Citylength];//????
	unsigned int srcTime;//???????
	unsigned int destTime;//???????
	int period;//???????
	double price;//???
}Line;

typedef struct adjNode {
	string adjCity;// [Citylength];//???????
	vector <Line> timetable;//????
	struct adjNode *nextcity;
}adjNode;

typedef struct FirstNode {
	string City;// [Citylength];//??????
	adjNode  *first;//??????
	int status;
}FirstNode, AdjList[MAXNUMBER];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;

int Cityname_to_number(string City)
{
	if (City == "BJP")
		return 0;
	else if (City == "SHH")
		return 1;
	else if (City == "TJP")
		return 2;
	else if (City == "CCT")
		return 3;
	else if (City == "CDW")
		return 4;
	else if (City == "FZS")
		return 5;
	else if (City == "GIW")
		return 6;
	else if (City == "GZQ")
		return 7;
	else if (City == "HBB")
		return 8;
	else if (City == "HHC")
		return 9;
	else if (City == "KMM")
		return 10;
	else if (City == "LZJ")
		return 11;
	else if (City == "NCG")
		return 12;
	else if (City == "NNZ")
		return 13;
	else if (City == "SYT")
		return 14;
	else if (City == "WHN")
		return 15;
	else if (City == "XAY")
		return 16;
	else if (City == "XNO")
		return 17;
	else if (City == "ZZF")
		return 18;
	else if (City == "DLT")
		return 19;
	else if (City == "LZZ")
		return 20;
	else if (City == "SZQ")
		return 21;
	else if (City == "XCH")
		return 22;
	else if (City == "ZZQ")
		return 23;
	else if (City == "WAR")
		return 24;
	else return -1;
}//map

string number_to_Cityname(int number)
{
	if (number == 0)
		return "BJP";
	else if (number == 1)
		return "SHH";
	else if (number == 2)
		return "TJP";
	else if (number == 3)
		return "CCT";
	else if (number == 4)
		return "CDW";
	else if (number == 5)
		return "FZS";
	else if (number == 6)
		return "GIW";
	else if (number == 7)
		return "GZQ";
	else if (number == 8)
		return "HBB";
	else if (number == 9)
		return "HHC";
	else if (number == 10)
		return "KMM";
	else if (number == 11)
		return "LZJ";
	else if (number == 12)
		return "NCG";
	else if (number == 13)
		return "NNZ";
	else if (number == 14)
		return "SYT";
	else if (number == 15)
		return "WHN";
	else if (number == 16)
		return "XAY";
	else if (number == 17)
		return "XNO";
	else if (number == 18)
		return "ZZF";
	else if (number == 19)
		return "DLT";
	else if (number == 20)
		return "LZZ";
	else if (number == 21)
		return "SZQ";
	else if (number == 22)
		return "XCH";
	else if (number == 23)
		return "ZZQ";
	else if (number == 24)
		return "WAR";
	else
		return"False";
}//map

int initialGraph(ALGraph &G)
{
	int i = 0;
	for (i = 0; i < MAXNUMBER; i++)
	{
		G.vertices[i].City = number_to_Cityname(i);//?????????
		G.vertices[i].first = NULL;
		G.vertices[i].status = 0;
	}
	G.vexnum = 0;
	G.arcnum = 0;
	G.kind = 0;//???
	return OK;
}

int printCity(ALGraph G)
{
	for (int i = 0; i < MAXVERTEX; i++)
	{
		if (G.vertices[i].status == 1)
		{
			if (i == 0)
				cout << "BJP 北京\n";
			else if (i == 1)
				cout << "SHH 上海\n";
			else if (i == 2)
				cout << "TJP 天津\n";
			else if (i == 3)
				cout << "CCT 长春\n";
			else if (i == 4)
				cout << "CDW 成都\n";
			else if (i == 5)
				cout << "FZS 福州\n";
			else if (i == 6)
				cout << "GIW 贵阳\n";
			else if (i == 7)
				cout << "GZQ 广州\n";
			else if (i == 8)
				cout << "HBB 哈尔滨\n";
			else if (i == 9)
				cout << "HHC 呼和浩特\n";
			else if (i == 10)
				cout << "KMM 昆明\n";
			else if (i == 11)
				cout << "LZJ 兰州\n";
			else if (i == 12)
				cout << "NCG 南昌\n";
			else if (i == 13)
				cout << "NNZ 南宁\n";
			else if (i == 14)
				cout << "SYT 沈阳\n";
			else if (i == 15)
				cout << "WHN 武汉\n";
			else if (i == 16)
				cout << "XAY 西安\n";
			else if (i == 17)
				cout << "XNO 西宁\n";
			else if (i == 18)
				cout << "ZZF 郑州\n";
			else if (i == 19)
				cout << "DLT 大连\n";
			else if (i == 20)
				cout << "LZZ 柳州\n";
			else if (i == 21)
				cout << "SZQ 深圳\n";
			else if (i == 22)
				cout << "XCH 徐州\n";
			else if (i == 23)
				cout << "ZZQ 株洲\n";
			else if (i == 24)
				cout << "WAR 乌鲁木齐\n";
			else;
		}
	}
	return OK;
}

int addCity(string city, ALGraph &G)
{
	int i = Cityname_to_number(city);
	if (G.vertices[i].status == 0)
	{
		G.vertices[i].status = 1;
		G.vexnum++;
	}
	else cout << "Has already in\n";
	return OK;
}

int delCity(string city, ALGraph &G)
{
	int i = Cityname_to_number(city);
	if (G.vertices[i].status == 1)
	{
		G.vertices[i].status = 0;
		G.vertices[i].first = NULL;
		G.vexnum--;
		for (i = 0; i < MAXVERTEX; i++)
		{
			adjNode* p = G.vertices[i].first;
			adjNode* temp = p;
			while (temp&&temp->adjCity != city)temp = temp->nextcity;
			while (p&&p->adjCity!=city&&p->nextcity&&p->nextcity->adjCity != city)p = p->nextcity;
			if (p&&temp)
			{
				if (p == G.vertices[i].first)
					if (p->adjCity == city)
						G.vertices[i].first = p->nextcity;
					else
						p->nextcity = temp->nextcity;
				else if (temp)
					p->nextcity = temp->nextcity;
				else;
			}
		}
	}
	else cout << "Has already del\n";
	return OK;
}

int addLine(Line l, ALGraph &G)
{
	int num = Cityname_to_number(l.src);
	if (G.vertices[num].first == NULL)
	{
		G.vertices[num].first = new adjNode;
		adjNode *p = G.vertices[num].first;
		p->adjCity = l.dest;
		p->nextcity = NULL;
		p->timetable.push_back(l);
	}
	else
	{
		adjNode *p = G.vertices[num].first;
		while (p != NULL)
		{
			if (p->adjCity == l.dest)
			{
				p->timetable.push_back(l);
				break;
			}
			p = p->nextcity;
		}
		if (p == NULL)
		{
			p = new adjNode;
			p->adjCity = l.dest;
			p->timetable.push_back(l);
			p->nextcity = G.vertices[num].first;
			G.vertices[num].first = p;
		}
	}
	return OK;
}

int delLine(Line l, ALGraph &G)
{
	int num = Cityname_to_number(l.src);
	adjNode *ptr = G.vertices[num].first;
	while (ptr&&ptr->adjCity != l.dest)ptr = ptr->nextcity;
	adjNode *pbefore = G.vertices[num].first;
	while (pbefore&&pbefore->adjCity!=l.dest&&pbefore->nextcity->adjCity != l.dest)pbefore = pbefore->nextcity;
	if (ptr == NULL)
		cout << "No such City\n";
	else
	{
		unsigned int i = 0;
		for (i = 0; i < ptr->timetable.size(); i++)
			if (ptr->timetable[i].Linename == l.Linename&&ptr->timetable[i].dest == l.dest&&ptr->timetable[i].destTime == l.destTime&&ptr->timetable[i].price == l.price&&ptr->timetable[i].srcTime==l.srcTime)
			{
				ptr->timetable.erase(ptr->timetable.begin() + i);
				cout << "Delete complete\n";
				if (ptr->timetable.size() == 0)
				{
					pbefore->nextcity = ptr->nextcity;
					//free(ptr);//???????
				}
				break;
			}
			else if (i == ptr->timetable.size() - 1)
				cout << "No such Line\n";
			else;
	}
	return 0;
}

typedef unsigned int time_u;

time_u time_to_uint(string _time) {
	size_t colon = _time.find_first_of(':');
	if (colon == string::npos || colon + 1 >= _time.length())
		return 0;
	string s_hour, s_minute;
	s_hour = _time.substr(0, colon);
	s_minute = _time.substr(colon + 1, _time.length() - colon - 1);
	stringstream ss;
	time_u t_hour = 0, t_minute = 0;
	ss.clear(); ss << s_hour; ss >> t_hour;
	ss.clear(); ss << s_minute; ss >> t_minute;
	return t_hour * 60 + t_minute;
}

string uint_to_time(time_u _time) {
	time_u t_hour, t_minute;
	t_hour = _time / 60; t_minute = _time % 60;

	stringstream ss;
	ss.fill('0');
	ss.width(2); ss << t_hour << ":";
	ss.width(2); ss << t_minute;
	return ss.str();
}

int minimalPrice(string src, string dest, ALGraph G, double dist[], int before[], Line beforeLine[])
{
	for (int i = 0; i < MAXVERTEX; i++)
		dist[i] = MAXPRICE;
	for (int count_before = 0; count_before < MAXVERTEX; count_before++)
		before[count_before] = -1;
	for (int count_before = 0; count_before < MAXVERTEX; count_before++)
		beforeLine[count_before].Linename = "empty";
	bool visited[MAXVERTEX] = { false };
	int root = Cityname_to_number(src);
	dist[root] = 0;
	visited[root] = true;
	int curr = root;
	Line tempLine;
	int countcitynum = 1;
	while (true)
	{
		FirstNode f = G.vertices[curr];
		adjNode *p = f.first;
		while (p)
		{
			double minimalPrice = p->timetable[0].price;
			tempLine.Linename = p->timetable[0].Linename;
			tempLine.dest = p->timetable[0].dest;
			tempLine.destTime = p->timetable[0].destTime;
			tempLine.period = p->timetable[0].period;
			tempLine.price = p->timetable[0].price;
			tempLine.src = p->timetable[0].src;
			tempLine.srcTime = p->timetable[0].srcTime;
			for (unsigned int count = 0; count<(p->timetable.size()); count++)
			{
				if (minimalPrice >(p->timetable[count].price))
				{
					minimalPrice = p->timetable[count].price;
					tempLine.Linename = p->timetable[count].Linename;
					tempLine.dest = p->timetable[count].dest;
					tempLine.destTime = p->timetable[count].destTime;
					tempLine.period = p->timetable[count].period;
					tempLine.price = p->timetable[count].price;
					tempLine.src = p->timetable[count].src;
					tempLine.srcTime = p->timetable[count].srcTime;
				}

			}
			if (!visited[Cityname_to_number(p->adjCity)] && (dist[Cityname_to_number(p->adjCity)]>(dist[curr] + minimalPrice)))
			{
				dist[Cityname_to_number(p->adjCity)] = dist[curr] + minimalPrice;
				before[Cityname_to_number(p->adjCity)] = curr;
				beforeLine[Cityname_to_number(p->adjCity)] = tempLine;
			}
			p = p->nextcity;
		}

		int j = -1;
		while (visited[++j]);
		int minvex = j;
		for (; j < MAXVERTEX; j++)
		{
			if (!visited[j] && dist[j] < dist[minvex])
				minvex = j;
		}

		if (countcitynum >= G.vexnum)
			break;
		curr = minvex;
		visited[curr] = true;
		countcitynum++;
	}
	int destnum = Cityname_to_number(dest);
	int tempforpath = destnum;
	if (before[tempforpath] != -1)
	{
		cout << "Lowest price is " << dist[destnum] << "\n";
		cout << "You should take \n";
	}
	while (tempforpath != root)
	{
		if (before[tempforpath] == -1)
		{
			cout << "No such Line\n";
			break;
		}
		cout << beforeLine[tempforpath].Linename << ' ' << beforeLine[tempforpath].src << ' '<< beforeLine[tempforpath].dest <<' ';
		cout<< uint_to_time(beforeLine[tempforpath].srcTime) <<' '<< uint_to_time(beforeLine[tempforpath].destTime) <<' ' <<uint_to_time(beforeLine[tempforpath].period)<<' '<<beforeLine[tempforpath].price << " \n";
		tempforpath = before[tempforpath];
	}
	return OK;
}
//minimal_time?????????
typedef struct {
	Line* line;				//??????????е??ó??г?????Line
	unsigned int time_arrive;	//?????ó??е????
	int time_cost;			//???ó??е?????
	int belong;				//????ó?????????????S
}InfoNode;

//mininal_time????????
//time_arrive?????v??city???????????v-city·?????????絽??city????????line????????÷?????????v????????·??????
//??????????????????????У??????????????????????????
//v???????????
int Earlest_Arrive_Cost(int v, adjNode* city, unsigned int time_arrive, Line** line) {
	Line* temp_line;
	unsigned int cost = 0;
	unsigned int min_cost = INFTY;

	for (unsigned int i = 0; i < city->timetable.size(); i++) {
		temp_line = &city->timetable[i];
		if (temp_line->srcTime >= time_arrive) cost = temp_line->srcTime - time_arrive + temp_line->period;	//??time_arrive???????????????????
		else cost = temp_line->srcTime + 1440 - time_arrive + temp_line->period;	//??time_arrive????????
		if (cost < min_cost) {	//????????·??
			min_cost = cost;
			*line = temp_line;
		}
	}
	return min_cost;
}

int minimalTime(string src, string dest, ALGraph G)
{
	unsigned int i = 0;
	int s = Cityname_to_number(src);	//???????
	int t = Cityname_to_number(dest);	//????????

	if (s == t) {
		cout << "The src and dest is the same city\n";
		return 0;
	}
	//??src??dest????
	vector <InfoNode*> Info;	//?????????????firstline????????InfoNode????????????vector?е????????
	int firstline_count = 0;	//?????????firstline, useful initialization

	adjNode* city1 = NULL; 	//????????????б???????Line??????
	Line* line1 = NULL;			//????????????б???????Line
	InfoNode* InfoArray = NULL;//????
	int w = 0;			//????????г??????????????????

	adjNode* city = NULL;
	Line* line = NULL;
	int v = 0, u = 0;
	int flag = 1;	//??S?????е?????????s??????S?????flag??????????, useful initialization
	int cost = 0;
	int temp_short = INFTY;	//?????u??????б????????????·?????????????????ζ?u????????????е???С?, useful initialization
	int temp_short_node = 0;	//??temp_short?????u??

	for (city1 = G.vertices[s].first; city1; city1 = city1->nextcity) { //??????????????
		for (i = 0; i < city1->timetable.size(); i++) {  //?????????????????·??
            flag = 1;
			line1 = &city1->timetable[i]; //?????firstline
			temp_short = INFTY; //???????
			InfoArray = new InfoNode[MAXNUMBER];	//??????????InfoNode??????
			for (int j = 0; j<MAXNUMBER; j++) { InfoArray[j].time_cost = INFTY; InfoArray[j].belong = 0; }	//InfoArray?????
			InfoArray[s].time_arrive = line1->srcTime;
			InfoArray[s].time_cost = 0;
			InfoArray[s].belong = 1;	//??s????S????
			w = Cityname_to_number(line1->dest);	//?????????
			InfoArray[w].line = line1;
			InfoArray[w].time_arrive = line1->destTime;
			InfoArray[w].time_cost = line1->period;
			InfoArray[w].belong = 1;	//??w????S????
			if (w == t) {
				Info.push_back(InfoArray);
				firstline_count++;
				continue;
			}	//?????line???????????????????????????????S?????

			while (flag) {	//??S?????е?????????s??????S?????flag??????????S?????
				flag = 0;
				temp_short = INFTY;
				for (v = 0; v<MAXNUMBER; v++) {
					if (v != s && InfoArray[v].belong) {	//v??S????v????s
						for (city = G.vertices[v].first; city; city = city->nextcity) {
							u = Cityname_to_number(city->adjCity);
							//u(city)????v??????
							if (!InfoArray[u].belong) {	//u????S??
								flag = 1;
								cost = Earlest_Arrive_Cost(v, city, InfoArray[v].time_arrive, &line);
								if (cost + InfoArray[v].time_cost < InfoArray[u].time_cost) {	//??u???????????·??
									InfoArray[u].line = line;
									InfoArray[u].time_arrive = line->destTime;  //(InfoArray[v].time_arrive + cost) % 1440;
									InfoArray[u].time_cost = InfoArray[v].time_cost + cost;
								}
								if (InfoArray[u].time_cost < temp_short) {
									temp_short = InfoArray[u].time_cost;
									temp_short_node = u;
								}
							}
						}//v?????u?????????
					}
				}//????v?????????
				InfoArray[temp_short_node].belong = 1;
				if (temp_short_node == t) break;	//?????????S
			}//while????
			if (InfoArray[t].belong) { Info.push_back(InfoArray); firstline_count++; }	//???????????S???????Array????Info vector
			else;	//??????firstline??????????·?????t(????????????s????????t)
		}   //?????????????????·???????
	}   //?????????????е????

	if (firstline_count) {
		//???鲻?firstline?????????С?
		temp_short = Info[--firstline_count][t].time_cost;	//??????????С???temp_short??????
		int short_line = firstline_count;	//????????С??????firstline???
		for (firstline_count--; firstline_count >= 0; firstline_count--) {
			if (Info[firstline_count][t].time_cost < temp_short) {
				temp_short = Info[firstline_count][t].time_cost;
				short_line = firstline_count;
			}
			else;
		}
		//????
		cout << "You should take\n";
		cout << "This trip takes " << uint_to_time(Info[short_line][t].time_cost) << '\n';
		while (t != s) {
			line = Info[short_line][t].line;	//????line???????????????????????????????????????????
												//printf("%s/n", line->Linename);
			cout << line->Linename <<' '<<line->src <<' '<< line->dest <<' '<<uint_to_time(line->srcTime)<<' '<<uint_to_time(line->destTime)<<' '<< uint_to_time(line->period)<<' '<<line->price << '\n';
			t = Cityname_to_number(line->src);
		}
	}
	else cout << "No such Line\n";
	return 0;
}

void Filein(ALGraph &G,ALGraph &G_Plane)
{
	int Linenum, Citynum;
	Line L;
	string File_or_not;
	string temp_src, temp_dest, temp_period, temp_cityname;
	cout << "For Train: File or not? Yes or No\n";
	cin >> File_or_not;
	if (File_or_not == "Yes")
	{
		ifstream myfile("Data.txt");
		if (!myfile.is_open())
			cout << "Open error\n";
		myfile >> Citynum;
		while (Citynum > 0)
		{
			myfile >> temp_cityname;
			addCity(temp_cityname, G);
			Citynum--;
		}
		myfile >> Linenum;
		for (int count = 0; count < Linenum; count++)
		{
			myfile >> L.Linename >> L.src >> L.dest >> temp_src >> temp_dest >> temp_period >> L.price;
			L.srcTime = time_to_uint(temp_src);
			L.destTime = time_to_uint(temp_dest);
			L.period = time_to_uint(temp_period);
			addLine(L, G);
		}
		myfile.close();
	}
	else
	{
		cout << "Please input Citynum\n";
		cin >> Citynum;
		while (Citynum > 0)
		{
			cin >> temp_cityname;
			addCity(temp_cityname, G);
			Citynum--;
		}
		cout << "Please input Linenum\n";
		cin >> Linenum;
		cout << "Please input Line\n";
		for (int count = 0; count < Linenum; count++)
		{
			cin >> L.Linename >> L.src >> L.dest >> temp_src >> temp_dest >> temp_period >> L.price;
			L.srcTime = time_to_uint(temp_src);
			L.destTime = time_to_uint(temp_dest);
			L.period = time_to_uint(temp_period);
			addLine(L, G);
		}
	}
	cout << "For Plane: File or not? Yes or No\n";
	cin >> File_or_not;
	if (File_or_not == "Yes")
	{
		ifstream myfile("Data_Plane.txt");
		if (!myfile.is_open())
			cout << "Open error\n";
		myfile >> Citynum;
		while (Citynum > 0)
		{
			myfile >> temp_cityname;
			addCity(temp_cityname, G_Plane);
			Citynum--;
		}
		myfile >> Linenum;
		for (int count = 0; count < Linenum; count++)
		{
			myfile >> L.Linename >> L.src >> L.dest >> temp_src >> temp_dest >> temp_period >> L.price;
			L.srcTime = time_to_uint(temp_src);
			L.destTime = time_to_uint(temp_dest);
			L.period = time_to_uint(temp_period);
			addLine(L, G_Plane);
		}
		myfile.close();
	}
	else
	{
		cout << "Please input Citynum\n";
		cin >> Citynum;
		while (Citynum > 0)
		{
			cin >> temp_cityname;
			addCity(temp_cityname, G_Plane);
			Citynum--;
		}
		cout << "Please input Linenum\n";
		cin >> Linenum;
		cout << "Please input Line\n";
		for (int count = 0; count < Linenum; count++)
		{
			cin >> L.Linename >> L.src >> L.dest >> temp_src >> temp_dest >> temp_period >> L.price;
			L.srcTime = time_to_uint(temp_src);
			L.destTime = time_to_uint(temp_dest);
			L.period = time_to_uint(temp_period);
			addLine(L, G_Plane);
		}
	}
}

void Inquire(ALGraph G,ALGraph G_plane)
{
	string src, dest;
	double dist[MAXVERTEX];
	int before[MAXVERTEX];
	Line beforeLine[MAXVERTEX];
	cout << "Please input src" << "\n";
	cin >> src;
	cout << "Please input dest" << "\n";
	cin >> dest;
	string vehicle;
	string PorT;//price or time
	cout << "Train or Plane? Use 'None' to quit\n";
	cin >> vehicle;
	cout << "Price or Time?\n";
	cin >> PorT;
	if (vehicle == "Train")
		if (PorT == "Price")
			minimalPrice(src, dest, G, dist, before, beforeLine);
		else if (PorT == "Time")
			minimalTime(src, dest, G);
		else;
	else if (vehicle == "Plane")
		if (PorT == "Price")
			minimalPrice(src, dest, G_plane, dist, before, beforeLine);
		else if (PorT == "Time")
			minimalTime(src, dest, G_plane);
		else;
		/*else if (vehicle == "None")
		break;*/
	else
		cout << "Wrong input!";
}
int main(void)
{
	ALGraph G;
	initialGraph(G);
	ALGraph G_Plane;
	initialGraph(G_Plane);
	Filein(G, G_Plane);
	Line L;
	string temp_src, temp_dest, temp_period, temp_cityname;
	while (true)
	{
		printCity(G);
		cout << "inquire ,addCity, delCity, addLine, delLine?\nuse None to quit\n";
		string act;
		cin >> act;
		if (act == "inquire")
			Inquire(G,G_Plane);
		else if (act == "addCity")
		{
			cout << "Please input city's name\n";
			string cityname;
			cin >> cityname;
			cout << "Train or Plane\n";
			string choose;
			cin >> choose;
			while (true)
			{
				if (choose == "Train")
				{
					addCity(cityname, G);
					break;
				}
				else if (choose == "Plane")
				{
					addCity(cityname, G_Plane);
					break;
				}
				else
					cout << "Wrong input!\n";
			}
		}
		else if (act == "delCity")
		{
			cout << "Please input city's name\n";
			string cityname;
			cin >> cityname;
			cout << "Train or Plane\n";
			string choose;
			cin >> choose;
			while (true)
			{
				if (choose == "Train")
				{
					delCity(cityname, G);
					break;
				}
				else if (choose == "Plane")
				{
					delCity(cityname, G_Plane);
					break;
				}
				else
					cout << "Wrong input!\n";
			}
		}
		else if (act == "addLine")
		{
			cout << "Please input Line\n";
			cin >> L.Linename >> L.src >> L.dest >> temp_src >> temp_dest >> temp_period >> L.price;
			L.srcTime = time_to_uint(temp_src);
			L.destTime = time_to_uint(temp_dest);
			L.period = time_to_uint(temp_period);
			cout << "Train or Plane\n";
			string choose;
			cin >> choose;
			while (true)
			{
				if (choose == "Train")
				{
					addLine(L, G);
					break;
				}
				else if (choose == "Plane")
				{
					addLine(L, G_Plane);
					break;
				}
				else
					cout << "Wrong input!\n";
			}
		}
		else if (act == "delLine")
		{
			cout << "Please input Line\n";
			cin >> L.Linename >> L.src >> L.dest >> temp_src >> temp_dest >> temp_period >> L.price;
			L.srcTime = time_to_uint(temp_src);
			L.destTime = time_to_uint(temp_dest);
			L.period = time_to_uint(temp_period);
			cout << "Train or Plane\n";
			string choose;
			cin >> choose;
			while (true)
			{
				if (choose == "Train")
				{
					delLine(L, G);
					break;
				}
				else if (choose == "Plane")
				{
					delLine(L, G_Plane);
					break;
				}
				else
					cout << "Wrong input!\n";
			}
		}
		else if (act == "None")
		{
			break;
		}
		else
			cout << "Wrong input\n";
	}
	return 0;
}
