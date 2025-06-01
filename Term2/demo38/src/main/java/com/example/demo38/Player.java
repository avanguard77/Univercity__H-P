package com.example.demo38;

import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.Date;

public class Player extends Car {
    public int life = 0;
    boolean ghostmode=true;
    boolean deathcheck=true;

    public Player(int x, int y, int hight, int width, String add, Pane pane) {
        super(x, y, hight, width, add, pane);

    }

    public void death(String s, int score, double time, int itemdestroy, String date) {
        Stage stage = new Stage();
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("Show_score.fxml"));
        fxmlLoader.setController(new ShowScore(s, score, time, itemdestroy, date));
        Scene scene = null;
        try {
            scene = new Scene(fxmlLoader.load(), 450, 250);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
        Stage oldStage = (Stage) pane.getScene().getWindow();
        oldStage.close();
    }

}