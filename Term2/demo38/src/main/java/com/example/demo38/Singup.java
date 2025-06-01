package com.example.demo38;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

import java.io.FileWriter;
import java.io.IOException;

public class Singup {
    @FXML
    Button btn;
    @FXML
    TextField username, password;
    @FXML
    Pane pane;

    @FXML
    public void initialize() {


        btn.setOnAction(_ -> {
            String us1 = String.valueOf(username);
            String pw = String.valueOf(username);

            try {
                if (us1 == null && pw == null) {
                    Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
                    alert.setContentText("ERROR");
                    alert.show();
                }else {
                    FileWriter fw = new FileWriter("gameInformation.txt", true);
                    fw.write(STR."\{username.getText()}\n");
                    FileWriter us = new FileWriter(STR."\{username.getText()}.txt", true);
                    fw.write(STR."\{password.getText()}\n");
                    fw.close();

                    Stage stage = new Stage();
                    FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("Sing_in.fxml"));
                    fxmlLoader.setController(new SingIn());
                    Scene scene = null;
                    try {
                        scene = new Scene(fxmlLoader.load(), 450, 600);
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                    stage.setTitle("Hello!");
                    stage.setScene(scene);
                    stage.show();
                    Stage oldStage = (Stage) pane.getScene().getWindow();
                    oldStage.close();

                    Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
                    alert.setContentText("COMPLETED");
                    alert.show();
                }

            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        });
    }
}
