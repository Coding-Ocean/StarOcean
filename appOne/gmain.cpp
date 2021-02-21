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
    int img = loadImage("assets\\unko.png");
    //�ʒu�f�[�^��num�p�ӂ���
    struct POS {
        float x, y, z;
    };
    const int num = 1000;
    struct POS p[num];
    //���������_���ɔz�u����
    for (int i = 0; i < num; i++) {
        p[i].x = random(-0.7f, 0.7);
        p[i].y = random(-0.5f, 0.5f);
        p[i].z = random(0.0f, 1.0f);
    }
    //�|�C���gor�摜�̕\���p�t���b�O
    bool flag = true;
    //�J�[�\����\��
    ShowCursor(FALSE);
    //���C�����[�v
    while (notQuit) {
        //�������O�Ɉړ�
        for (int i = 0; i < num; i++) {
            p[i].z += -0.008f;
            if (p[i].z <= 0.0f) {
                p[i].z = 1.0f;
            }
        }
        //�Q�O�����炢�����̍��œh��Ԃ����O�Ղ�`��
        strokeWeight(0);
        fill(0, 0, 0, 60);
        rectMode(CORNER);
        rect(0, 0, width, height);
        //�|�C���gor�摜��`��
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
    //�J�[�\���\��
    ShowCursor(TRUE);
}

#endif