package com.example.demo38;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;
import javafx.util.Duration;

import java.io.File;

public class Car {
    boolean check =true;
    protected ImageView imageView;
    protected String add;
    protected Pane pane;

    public int getX() {
        return (int) imageView.getX();
    }

    public void setX(double x) {
        imageView.setX(x);
    }

    public int getY() {
        return (int) imageView.getY();
    }

    public void setY(double y) {
        imageView.setY(y);
    }

    public double getHight() {
        return imageView.getFitHeight();
    }

    public void setHight(double hight) {
        imageView.setFitHeight(hight);
    }

    public double getWidth() {
        return imageView.getFitWidth();
    }

    public void setWidth(double width) {
        this.imageView.setFitWidth(width);
    }

    public ImageView getImageView() {
        return imageView;
    }

    public void setImageView(ImageView imageView) {
        this.imageView = imageView;
    }


    public void addToPane() {
        pane.getChildren().add(imageView);
    }

    public void removeToPane() {
        pane.getChildren().remove(imageView);

    }
    public Car(int x, int y, int height, int width, String add, Pane pane) {

        this.add = add;
        this.pane = pane;
        File file = new File(add);
        Image image = new Image(file.toURI().toString());
        imageView = new ImageView(image);
        imageView.setX(x);
        imageView.setY(y);
        imageView.setFitHeight(height);
        imageView.setFitWidth(width);
    }
    public void move(){
        Timeline timeline = new Timeline();
        KeyFrame keyFrame = new KeyFrame(Duration.millis(45), actionEvent -> {
            imageView.setY(imageView.getY() + 10);
        });
        timeline.getKeyFrames().add(keyFrame);
        timeline.setCycleCount(Timeline.INDEFINITE);
        timeline.play();

    }
}
