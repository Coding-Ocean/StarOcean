#if 0

#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    while (notQuit) {
        clear(80);
    }
}

#else

#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    //画像読み込み
    int img = loadImage("assets\\unko.png");
    //位置データをnum個用意する
    struct POS {
        float x, y, z;
    };
    const int num = 1000;
    struct POS p[num];
    //星をランダムに配置する
    for (int i = 0; i < num; i++) {
        p[i].x = random(-0.7f, 0.7);
        p[i].y = random(-0.5f, 0.5f);
        p[i].z = random(0.0f, 1.0f);
    }
    //ポイントor画像の表示用フラッグ
    bool flag = true;
    //カーソル非表示
    ShowCursor(FALSE);
    //メインループ
    while (notQuit) {
        //奥から手前に移動
        for (int i = 0; i < num; i++) {
            p[i].z += -0.008f;
            if (p[i].z <= 0.0f) {
                p[i].z = 1.0f;
            }
        }
        //２０％ぐらい透明の黒で塗りつぶす→軌跡を描く
        strokeWeight(0);
        fill(0, 0, 0, 60);
        rectMode(CORNER);
        rect(0, 0, width, height);
        //ポイントor画像を描く
        mathAxis(1,0,0);
        strokeWeight(20);
        if (isTrigger(KEY_Z))flag = !flag;
        for (int i = 0; i < num; i++) {
            float x = p[i].x;
            float y = p[i].y;
            float z = p[i].z;
            float size = 1.0f - z;
            strokeWeight(size * 20);
            stroke(200, 255, 255);
            if (flag) {
                mathPoint(x / z, y / z);
            }
            else {
                rectMode(CENTER);
                mathImage(img, x / z, y / z, 0, size);
            }
        }
    }
    //カーソル表示
    ShowCursor(TRUE);
}

#endif