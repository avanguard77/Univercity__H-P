package com.example.demo38;

import javafx.beans.property.SimpleStringProperty;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
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

public class States {
    @FXML
    Button btn;
    @FXML
    Pane pane;
    String fusername;


    public States(String username) {
        this.fusername = username;
    }

    @FXML
    TableView tstates;
    @FXML
    TableColumn<UserData, String> tscore, ttime, tcud, tlp;

    @FXML
    public void initialize() {

        tscore.setCellValueFactory(new PropertyValueFactory<>("score"));
        ttime.setCellValueFactory(new PropertyValueFactory<>("time"));
        tcud.setCellValueFactory(new PropertyValueFactory<>("id"));
        tlp.setCellValueFactory(new PropertyValueFactory<>("date"));

        Scanner scanner = null;
        try {
            scanner = new Scanner(new File(STR."\{fusername}.txt"));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        while (scanner.hasNextLine()) {
            int ss = Integer.parseInt(scanner.nextLine());
            double st = Double.parseDouble(scanner.nextLine());
            int sid = Integer.parseInt(scanner.nextLine());
            String sd = scanner.nextLine();
            UserData userData = new UserData(ss, st, sid, sd);
            tstates.getItems().add(userData);
        }

        btn.setOnAction(actionEvent -> {
            Stage stage = new Stage();
            FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("Menu_Start.fxml"));
            fxmlLoader.setController(new HelloMenuStart(fusername));
            Scene scene = null;
            try {
                scene = new Scene(fxmlLoader.load(), 1000, 600);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            stage.setTitle("Hello!");
            stage.setScene(scene);
            stage.show();
            Stage oldStage = (Stage) pane.getScene().getWindow();
            oldStage.close();
        });
    }
}

