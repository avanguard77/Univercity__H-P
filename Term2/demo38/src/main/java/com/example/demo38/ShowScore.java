package com.example.demo38;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Date;

public class ShowScore {
    @FXML
    Button btn, btn1;
    @FXML
    Pane pane;
    @FXML
    Label showScore, showTime, itemdestroyed, ldate;

    String fusername;
    int score, itemdestroy;
    double time;
    String date;

    public ShowScore(String username, int score, double time, int itemdestroy, String date) {
        this.fusername = username;
        this.score = score;
        this.time = time;
        this.itemdestroy = itemdestroy;
        this.date = date;
    }

    @FXML
    public void initialize() throws IOException {
        FileWriter fw = new FileWriter(STR."\{fusername}.txt", true);
        fw.write(STR."\{score}\n");
        fw.write(STR."\{(int) time}\n");
        fw.write(STR."\{itemdestroy}\n");
        fw.write(STR."\{date}\n");
        fw.close();


        showScore.setText(String.valueOf(score));
        showTime.setText(String.valueOf(time));
        itemdestroyed.setText(String.valueOf(itemdestroy));
        ldate.setText(String.valueOf(date));

        btn.setOnAction(actionEvent -> {
            Stage stage = new Stage();
            FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));
            fxmlLoader.setController(new HelloController(fusername));
            Scene scene = null;
            try {
                scene = new Scene(fxmlLoader.load(), 500, 800);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            stage.setScene(scene);
            stage.show();
            Stage oldStage = (Stage) pane.getScene().getWindow();
            oldStage.close();
        });
        btn1.setOnAction(actionEvent -> {
            Stage stage = new Stage();
            FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("Menu_Start.fxml"));
            fxmlLoader.setController(new HelloMenuStart(fusername));
            Scene scene = null;
            try {
                scene = new Scene(fxmlLoader.load(), 1000, 600);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            stage.setScene(scene);
            stage.show();
            Stage oldStage = (Stage) pane.getScene().getWindow();
            oldStage.close();
        });
    }
}
