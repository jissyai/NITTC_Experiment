//プログラム　http://tatsyblog.sakura.ne.jp/wordpress/applications/machine-learning/1331/
//MNISTについて　https://weblabo.oscasierra.net/python/ai-mnist-data-detail.html

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include <cmath>
#include <ctime>
#include <cstring>

#include "educnn.h"

int main(int argc, char** argv) {
	// 学習データの読み込み
	Matrix train_data = mnist::train_data();
	Matrix train_label = mnist::train_label();

	// 乱数の初期化
	Random* rng = new Random((unsigned int)time(0));

	// レイヤーの生成
	std::vector<AbstractLayer*> layers(2);
	layers[0] = new FullyConnectedLayer(rng, 784, 300);
	layers[1] = new FullyConnectedLayer(rng, 300, 10);

	// ニューラルネットの学習
	Network network(layers, train_data, train_label, 10);
	Timer timer;
	timer.start();
	network.train(1, 0.1, 0.5);
	printf("Time: %f sec\n", timer.stop());

	// テストデータの読み込み
	Matrix test_data = mnist::test_data();
	Matrix test_label = mnist::test_label();

	// テスト
	Matrix pred = network.predict(test_data);

	// 正解率の表示
	double ratio = check(pred, test_label);
	printf("ratio: %f %%\n", ratio);

	// メモリの解放
	delete rng;
	for (int i = 0; i < layers.size(); i++) {
		delete layers[i];
	}
}
