package com.example.demo38;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Date;
import java.util.Objects;
import java.util.Scanner;

public class SingIn {
    @FXML
    Button btn,btn1;
    @FXML
    TextField tusername, tpassword;
    @FXML
    Pane pane;
    int d=0,h=0;
    double g=0;
    Date date;

    @FXML
    public void initialize() {
        File file = new File("src/main/game/ghost.png");
        Image image = new Image(file.toURI().toString());
        ImageView imageView = new ImageView(image);
        imageView.setX(130);
        imageView.setY(50);
        imageView.setFitHeight(200);
        imageView.setFitWidth(200);
        pane.getChildren().addFirst(imageView);
        btn.setOnAction(actionEvent -> {

            Scanner scanner = null;
            try {
                scanner = new Scanner(new File("gameInformation.txt"));
            } catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }
            while (scanner.hasNextLine()) {
                String username = scanner.nextLine();
                String password = scanner.nextLine();
                if (Objects.equals(tpassword.getText(), password)&& Objects.equals(tusername.getText(), username)) {

                    Stage stage = new Stage();
                    FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("Menu_Start.fxml"));
                    fxmlLoader.setController(new HelloMenuStart(STR."\{tusername.getText()}"));
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
                }
            }
        });
        btn1.setOnAction(actionEvent1 -> {
            Stage stage = new Stage();
            FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("Sing-up.fxml"));
            fxmlLoader.setController(new Singup());
            Scene scene = null;
            try {
                scene = new Scene(fxmlLoader.load(), 400, 250);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            stage.setTitle("Sing up");
            stage.setScene(scene);
            stage.show();
            Stage oldStage = (Stage) pane.getScene().getWindow();
            oldStage.close();
        });
    }
}
