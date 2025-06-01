module com.example.demo38 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.demo38 to javafx.fxml;
    exports com.example.demo38;
}