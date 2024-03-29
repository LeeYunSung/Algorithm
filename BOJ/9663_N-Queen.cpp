#include <iostream>
using namespace std;

void N_Queen(int);

int N;//庚薦拭辞 爽嬢走澗 惟績毒税 滴奄
int queen_col[15];//蹄税 伸是帖研 煽舌拝 壕伸(queen_col税 昔畿什澗 切尻什傾 楳聖 税耕馬惟 吉陥)
int answer;//蹄聖 兜聖 呪 赤澗 鯵呪

bool isEmpty(int);//楳, 企唖識拭 Queen戚 赤澗走 貼事馬澗 敗呪

int main() {
	cin >> N;

	N_Queen(0);//1. 0楳採斗 貼事 貢 Queen 兜奄 獣拙
	cout << answer;//7. 舛岩 窒径

	return 0;
}

void N_Queen(int row) {
	if (row == N) {//2. 薄仙 貼事馬澗 楳戚 原走厳 楳拭 亀含梅陥檎 queen聖 乞砧 壕帖梅陥澗 倶戚糠稽 answer + 1 背爽奄
		answer++;
		return;//【希戚雌 貼事馬走 省壱 軒渡(bounding function)
	}
	for (int col = 0; col < N; ++col) {//3. queen聖 兜聖 呪 赤澗走 伸 貼事
		queen_col[row] = col;//4. 隔聖 呪 赤澗 queen税 切軒研 煽舌敗
		if (isEmpty(row)) {//5. 焼掘人 企唖識戚 搾嬢赤澗走 貼事
			N_Queen(row + 1);//6. Queen 兜壱 陥製 楳 貼事馬君 gogo
		}
	}
}

bool isEmpty(int row) {
	for (int col = 0; col < row; col++) {//5-1. 0楳採斗 薄仙 楳猿走 違帖澗 Queen戚 赤澗走 貼事廃陥.
		if (queen_col[row] == queen_col[col] //5-2. 旭精 伸拭 赤澗走 貼事
			|| abs(queen_col[row] - queen_col[col]) == (row - col)) {//5-3. 企唖識拭 赤澗走 貼事
				return false;//【Queen聖 兜聖 呪 蒸陥檎 希戚雌 貼事馬走 省壱 return(bounding function)
		}
	}
	return true;
}


/*
[繕闇庚 竺誤]
1. queen_col[col] == queen_col[row]

0 1 2 3 <- 楳聖 税耕
けけけけ <- 伸税 是帖研 税耕

queen精 旭精 伸/楳 雌拭 兜戚檎 照鞠糠稽
col聖 +1 背爽悟 宜檎辞 queen_col拭 旭精 葵戚 煽舌鞠嬢 赤澗走研 溌昔廃陥.(旭精 葵戚 赤陥檎, 旭精 伸拭 赤陥澗 税耕艦苑)


2. abs(queen_col[row] - queen_col[col]) == (row - col)

0 1 2 3 <- 楳聖 税耕
けけけけ <- 伸税 是帖研 税耕

queen_col[]澗 queen_col拭 級嬢赤澗 葵戚糠稽 伸聖 税耕馬壱
row, col精 inxex戚糠稽 楳聖 税耕廃陥.
薄仙疎妊人 企唖識 疎妊税 伸税 託人 楳税 託亜 旭陥檎 企唖識拭 是帖廃 依聖 税耕廃陥.

森研 級嬢 薄仙 疎妊澗 0,0 戚壱, 薄仙 疎妊税 企唖識 疎妊澗 1,1 析 凶,
唖唖 伸精 伸葵企稽, 楳精 楳葵企稽 皐檎 0 - 1 == 0 - 1 戚 失験敗聖 硝 呪 赤陥.
*/