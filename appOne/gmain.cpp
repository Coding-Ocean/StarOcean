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
    int unkoImg = loadImage("assets\\unko.png");
    int ufoImg = loadImage("assets\\ufo.png");
    //位置データをnum個用意する
    struct POS {
        float x, y, z;
    };
    const int num = 300;
    struct POS p[num];
    //星をランダムに配置する
    for (int i = 0; i < num; i++) {
        p[i].x = random(-0.7f, 0.7f);
        p[i].y = random(-0.5f, 0.5f);
        p[i].z = random(0.1f, 1.0f);
    }
    //ポイントor画像の表示用スイッチ
    int sw = 0;
    //カーソル非表示
    ShowCursor(FALSE);
    //メインループ
    while (notQuit) {
        //半透明の黒で塗りつぶす→軌跡を描く
        strokeWeight(0);
        fill(0, 0, 0, 90);
        rectMode(CORNER);
        rect(0, 0, width, height);
        //手前に移動後、ポイントor画像を描く
        axisMode(NODRAW);
        mathAxis(1.0f);
        if (isTrigger(KEY_Z))++sw %= 3;
        rectMode(CENTER);
        stroke(200, 255, 200);
        for (int i = 0; i < num; i++) {
            //奥から手前に移動
            p[i].z += -0.008f;
            float x = p[i].x / p[i].z;
            float y = p[i].y / p[i].z;
            //ウィンドウから出たら奥に誕生させる
            if (p[i].z <= 0.0f ||
                x > 1.0f || x < -1.0f ||
                y > 0.56f || y < -0.56f
                ) {
                x = p[i].x = random(-0.7f, 0.7f);
                y = p[i].y = random(-0.5f, 0.5f);
                p[i].z = 1.0f;
            }
            //点or画像の描画
            float size = 1.0f - p[i].z;
            if (sw == 0) {
                strokeWeight(size * 20);
                mathPoint(x, y);
            }
            else if (sw == 1) {
                mathImage(ufoImg, x, y, 0, size);
            }
            else if (sw == 2) {
                mathImage(unkoImg, x, y, 0, size);
            }
        }
    }
    //カーソル表示
    ShowCursor(TRUE);
}

#endif