package com.example.demo38;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;

import java.io.File;

public class Life  {
    private int tedadlife;
    private ImageView imageView;
    private Pane pane;

    public Life(int tedadlife,Pane pane) {

        this.pane=pane;

        File file = new File("src/main/images/life.jpg");
        Image image = new Image(file.toURI().toString());
        this.imageView = new ImageView(image);
        imageView.setX(50*tedadlife);
        imageView.setY(0);
        imageView.setFitHeight(50);
        imageView.setFitWidth(50);
        pane.getChildren().add(imageView);
    }
    public void damage(){
        pane.getChildren().remove(imageView);
    }

    public int getTedadlife() {
        return tedadlife;
    }

    public void setTedadlife(int tedadlife) {
        this.tedadlife = tedadlife;
    }

    public ImageView getImageView() {
        return imageView;
    }

    public void setImageView(ImageView imageView) {
        this.imageView = imageView;
    }

}
