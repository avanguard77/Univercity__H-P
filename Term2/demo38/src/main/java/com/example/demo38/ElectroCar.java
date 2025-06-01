package com.example.demo38;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Line;
import javafx.util.Duration;

public class ElectroCar extends Enemey {
    public ElectroCar(int x, int y, int hight, int width, String add, Pane pane) {
        super(x, y, hight, width, add, pane);
        imageView.setRotate(180);
    }

    @Override
    public void move() {
        Timeline timelinee = new Timeline();
        KeyFrame keyFrame = new KeyFrame(Duration.millis(50), actionEvent -> {
            imageView.setY(imageView.getY() + 10);
        });
        timelinee.getKeyFrames().add(keyFrame);
        timelinee.setCycleCount(Timeline.INDEFINITE);
        timelinee.play();
    }

    public void fire() {
        pane.getChildren().add(new Line(0,getY(),800,getY()));
    }
}