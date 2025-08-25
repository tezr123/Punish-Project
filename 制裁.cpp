#include <jindutiao.h>
const int WAIT = 5;

struct Punish {	//惩罚结构体
	string content;	//惩罚内容
	int index;	//惩罚编号
};
vector<Punish> vecPunishList = {	//惩罚列表
	{"黑板清洁工：擦一节课的黑板", 1},
	{"小小调试员：将一串有Bug的代码修复", 2},
	{"知识回顾者：在下课前一分钟将课上讲的知识概括出来", 3},
	{"我是小模特：用大头照作为课间时大屏幕上的背景", 4},
	{"变量名风暴：根据老师提供的一个模糊的功能描述，写出3个不同风格但语义清晰的变量名", 5},
	{"我是小演员：模仿一个鬼畜视频10秒", 6},
	{"我是歌唱家：唱一首歌曲，要大声响亮，不少于30秒", 7},
	{"问题总动员：课上，由老师在合适时机问迟到者一个关于课上内容的问题", 8},
	{"时间赔偿者：迟到几分钟，课间刷几分钟编程题", 9},
	{"小小说书人：用一分钟时间向大家分享一个关于守时重要性的小故事或名言警句", 10},
	{"反思代码块：迟到者需要当场写一段代码，用多行注释 /* */ 详细“注释”出自己迟到的原因（至少列出3条），并用 printf 或 cout 语句输出一条道歉和保证下次准时的承诺。",11}
};
void outputList(vector<Punish>& punish) {	//输出惩罚列表
	for (auto it = punish.begin(); it < punish.end(); it++) {
		cout << '\t' << it->index << '.';
		lt.Sout(it->content, WAIT);
		cout << endl;
	}
}

void Punished(int num, vector<Punish>& punish) {
	system("cls");
	int people, array[num + 1] = {0}, dice_roll;
	cout << "有多少人要受惩罚：";
	cin >> people;
	system("cls");
	mt19937 engine;
	uniform_int_distribution<int> dist(1, num);
	random_device rd;
	engine.seed(rd());
	for (int i = 0; i < min(people, num); ++i) {
		do {
			dice_roll = dist(engine);
		} while (array[dice_roll]);
		array[dice_roll] = 1;
		cout << "第" << i + 1 << "个人的惩罚是：" << punish[dice_roll - 1].content << endl;
	}
	if (people > num) {
		for (int i = num; i < people; ++i) {
			dice_roll = dist(engine);
			cout << "第" << i + 1 << "个人的惩罚是：" << punish[dice_roll - 1].content << endl;
		}
	}

}

int main() {
	jindutiao.Jindutiao(35, 10, 0, 0, ' ', ' ', "加载", "low");
	cout << "******************************" << endl;
	cout << "*         惩罚小程序         *" << endl;
	cout << "*     让迟到的同学爽翻天     *" << endl;
	cout << "******************************" << endl;
	cout << "  由 LovelyYoung 和tezr123制作 " << endl;
	lt.DIYpause("请按下任意键，开始挑选礼包套餐……");
	system("cls");
	cout << "请选择（输入对应的数字）：" << endl;
	cout << "1.使用内设的惩罚（11个）" << endl;
	outputList(vecPunishList);
	cout << "2.在内设的惩罚的基础上追加惩罚" << endl;
	cout << "3.选择几项内设的惩罚并追加惩罚" << endl;
	cout << "4.自己输入惩罚" << endl;
	int in;
	cin >> in;
	switch (in) {
		case 1: {
			Punished(11, vecPunishList);
			break;
		}
		case 2: {
			cout << "请问你要输入多少个惩罚：";
			int cf;
			cin >> cf;
			if (cf) {
				vecPunishList.resize(11 + cf);
				cout << "请输入你的惩罚:";
				for (int i = 10; i < 11 + cf; i++) {
					cin >> vecPunishList[i].content;
					vecPunishList[i].index = i + 1;
				}
			}
			Punished(11 + cf, vecPunishList);
			break;
		}
		case 3: {
			cout << "请问你要选择几个惩罚:";
			int cf1;
			cin >> cf1;
			vector<Punish> vecPunishList2;
			if (cf1) {
				if (cf1 == 1) {
					cout << "请输入它的编号：";
				} else {
					cout << "请分别输入它们的编号：";
				}

				int cf2[cf1];
				for (int i = 0; i < cf1; i++) {
					cin >> cf2[i];
					vecPunishList2.push_back(vecPunishList[cf2[i]]);

				}
			}
			cout << "请问你要输入多少个惩罚：";
			int cf3;
			cin >> cf3;
			if (cf3) {
				vecPunishList2.resize(cf1 + cf3);
				cout << "请输入你的惩罚:";
				for (int i = cf1; i < cf1 + cf3; i++) {
					cin >> vecPunishList2[i].content;
					vecPunishList2[i].index = i + 1;
						Punished(cf1 + cf3, vecPunishList2);
				}
			}

			Punished(cf1 + cf3, vecPunishList2);

			break;
		}
		case 4: {
			cout << "请问你要输入多少个惩罚：";
			int cf4;
			cin >> cf4;
			if (cf4) {
				vector<Punish> vecPunishList3(cf4);
				cout << "请输入你的惩罚:";
				for (int i = 0; i < cf4; i++) {
					cin >> vecPunishList3[i].content;
					vecPunishList3[i].index = i + 1;
				}
				Punished(cf4, vecPunishList3);
			} else {
				cout << "你没有输入惩罚" << endl;
			}
			break;
		}
		default: {
			cout << "你是熊孩子吗？我偏不给你玩" << endl;
			break;
			return 0;
		}
	}
	_getch();
	return 0;
}
