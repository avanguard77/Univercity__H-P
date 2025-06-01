package com.example.demo38;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.scene.layout.Pane;
import javafx.util.Duration;

public class Van extends Enemey {
    public Van(int x, int y, int hight, int width, String add, Pane pane) {
        super(x, y, hight, width, add, pane);
        imageView.setRotate(180);
    }
}
