package com.example.demo38;


import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;
import javafx.util.Duration;

import java.io.File;

public class Fire extends Enemey{

    public Fire(int x, int y, int hight, int width, String add, Pane pane) {
        super(x, y, hight, width, add, pane);
    }

    public void addToPane() {
        pane.getChildren().add(imageView);
    }

    public void removeToPane() {
        pane.getChildren().remove(imageView);

        imageView.setY(800);
        imageView.setX(-300);
    }
    public void removeToPane1(int d,int f) {
        pane.getChildren().remove(imageView);

        File file1 = new File("src/main/game/fire.gif");
        Image image1 = new Image(file1.toURI().toString());
        ImageView imageView1 = new ImageView(image1);
        imageView1.setX(d);
        imageView1.setY(f);
        imageView1.setFitHeight(100);
        imageView1.setFitWidth(100);
        pane.getChildren().add(imageView1);

        Timeline tcheck1 = new Timeline();
        KeyFrame kchech1 = new KeyFrame(Duration.millis(500), actionEvent -> {
            pane.getChildren().remove(imageView1);
        });
        tcheck1.getKeyFrames().add(kchech1);
        tcheck1.setCycleCount(1);
        tcheck1.play();
        imageView.setY(-300);
        imageView.setX(-600);
    }

    public void move(int f,int d) {

        Timeline timeline = new Timeline();
        KeyFrame keyFrame = new KeyFrame(Duration.millis(25), actionEvent -> {
            imageView.setY(imageView.getY() + f);
            imageView.setX(imageView.getX()+d);
        });
        timeline.getKeyFrames().add(keyFrame);
        timeline.setCycleCount(Timeline.INDEFINITE);
        timeline.play();

    }
}