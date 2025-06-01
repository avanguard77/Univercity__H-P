package com.example.demo38;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

import java.io.File;
import java.io.IOException;
import java.util.Date;

public class HelloMenuStart {
    @FXML
    Button btn, btn1,btn2;
    @FXML
    Pane pane;
    String fusername;

    public HelloMenuStart(String username) {
        this.fusername=username;

    }

    @FXML
    public void initialize() {


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
            stage.setTitle("Hello!");
            stage.setScene(scene);
            stage.show();
            Stage oldStage=(Stage)pane.getScene().getWindow();
            oldStage.close();
        });
        btn1.setOnAction(actionEvent -> {
            Stage stage = new Stage();
            FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("States.fxml"));
            fxmlLoader.setController(new States(fusername));
            Scene scene = null;
            try {
                scene = new Scene(fxmlLoader.load(), 600, 600);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            stage.setTitle("Hello!");
            stage.setScene(scene);
            stage.show();
            Stage oldStage=(Stage)pane.getScene().getWindow();
            oldStage.close();
        });
        btn2.setOnAction(actionEvent -> {
            Stage stage = new Stage();
            FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("Sing_in.fxml"));
            fxmlLoader.setController(new SingIn());
            Scene scene = null;
            try {
                scene = new Scene(fxmlLoader.load(), 450, 400);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            stage.setTitle("Hello!");
            stage.setScene(scene);
            stage.show();
            Stage oldStage=(Stage)pane.getScene().getWindow();
            oldStage.close();
        });

        {int d= (int) (Math.random() * 3);
            String[] strings={"src/main/game/wall.gif","src/main/game/wall2.gif","src/main/game/wall3.gif"};
            File file = new File(strings[d]);
            Image image = new Image(file.toURI().toString());
            ImageView imageView = new ImageView(image);
            imageView.setX(0);
            imageView.setY(0);
            imageView.setFitHeight(600);
            imageView.setFitWidth(1000);
            pane.getChildren().addFirst(imageView);}
    }
}
