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
    //�摜�ǂݍ���
    int unkoImg = loadImage("assets\\unko.png");
    int ufoImg = loadImage("assets\\ufo.png");
    //�ʒu�f�[�^��num�p�ӂ���
    struct POS {
        float x, y, z;
    };
    const int num = 1000;
    struct POS p[num];
    //���������_���ɔz�u����
    for (int i = 0; i < num; i++) {
        p[i].x = random(-0.9f, 0.9f);
        p[i].y = random(-0.5f, 0.5f);
        p[i].z = random(0.0f, 1.0f);
    }
    //�|�C���gor�摜�̕\���p�X�C�b�`
    int sw = 0;
    //�J�[�\����\��
    ShowCursor(FALSE);
    //���C�����[�v
    while (notQuit) {
        //�������O�Ɉړ�
        for (int i = 0; i < num; i++) {
            p[i].z += -0.008f;
            if (
                p[i].x < -1.1f ||
                p[i].x > 1.1f ||
                p[i].y < -0.6f ||
                p[i].y > 0.6f ||
                p[i].z <= 0.0f
                ) {
                p[i].x = random(-0.9f, 0.9f);
                p[i].y = random(-0.5f, 0.5f);                p[i].z = 1.0f;
            }
        }
        //�Q�O�����炢�����̍��œh��Ԃ����O�Ղ�`��
        strokeWeight(0);
        fill(0, 0, 0, 50);
        rectMode(CORNER);
        rect(0, 0, width, height);
        //�|�C���gor�摜��`��
        mathAxis(1,0,0);
        strokeWeight(20);
        if (isTrigger(KEY_Z))++sw %= 3;
        for (int i = 0; i < num; i++) {
            float x = p[i].x;
            float y = p[i].y;
            float z = p[i].z;
            float size = 1.0f - z;
            strokeWeight(size * 20);
            stroke(200, 255, 255);
            if (sw==0) {
                mathPoint(x / z, y / z);
            }
            else if (sw == 1) {
                rectMode(CENTER);
                mathImage(unkoImg, x / z, y / z, 0, size);
            }
            else if (sw == 2) {
                rectMode(CENTER);
                mathImage(ufoImg, x / z, y / z, 0, size);
            }
        }
    }
    //�J�[�\���\��
    ShowCursor(TRUE);
}

#endif