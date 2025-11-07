#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
struct Result
{
    int mX, mY;
    int mMoveDistance;
    int mRideDistance;
    Result()
    {
        mX = mY = mMoveDistance = mRideDistance = -1;
    }
};

extern void init(int N, int M, int L, int mXs[], int mYs[]);
extern int pickup(int mSX, int mSY, int mEX, int mEY);
extern Result reset(int mNo);
extern void getBest(int mNos[]);

#define MAX_M 2000
#define CMD_INIT 100
#define CMD_PICKUP 200
#define CMD_RESET 300
#define CMD_GET_BEST 400

static bool run() {
	int q;
	scanf("%d", &q);

	int N, M, L;
	int mXs[MAX_N], mYs[MAX_K];
	int mSX, mSY, mEX, mTime, mEY;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
		case CMD_INIT:
			okay = true;
			scanf("%d %d %d", &N, &M, &L);
			for (int j = 0; j < N; ++j) {
				scanf("%d", &mChargeArr[j]);
			}
			for (int j = 0; j < k; ++j) {
				scanf("%d %d %d %d %d", &mIdArr[j], &sCityArr[j], &eCityArr[j], &mTimeArr[j], &mPowerArr[j]);
			}
			init(n, mChargeArr, k, mIdArr, sCityArr, eCityArr, mTimeArr, mPowerArr);
			break;
		case CMD_ADD:
			scanf("%d %d %d %d %d", &mId, &sCity, &eCity, &mTime, &mPower);
			add(mId, sCity, eCity, mTime, mPower);
			break;
		case CMD_REMOVE:
			scanf("%d", &mId);
			remove(mId);
			break;
		case CMD_COST:
			scanf("%d %d %d %d %d", &b, &sCity, &eCity, &ans, &m);
			for (int j = 0; j < m; ++j) {
				scanf("%d %d", &mCityArr[j], &mTimeArr[j]);
			}
			ret = cost(b, sCity, eCity, m, mCityArr, mTimeArr);
			if (ans != ret)
				okay = false;
			break;
		default:
			okay = false;
			break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}