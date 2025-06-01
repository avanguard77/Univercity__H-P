package com.example.demo38;

import javafx.animation.KeyFrame;
import javafx.animation.PauseTransition;
import javafx.animation.Timeline;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.util.Duration;

import java.io.File;
import java.util.ArrayList;
import java.util.Date;

public class HelloController {

    String fusername;

    public HelloController(String username) {
        this.fusername = username;
    }

    @FXML
    Pane pane;
    double time = 0;
    int itemdestroy = 0;
    Date date = new Date();
    String dt = String.valueOf(date);
    boolean gc = true;
    private int score = 0;
    double bpetrol = 100;
    @FXML
    Label tscore;
    Player player;
    ArrayList<Enemey> enemey1 = new ArrayList<>();
    ArrayList<Booster> bs = new ArrayList<>();
    ArrayList<Coin> coins = new ArrayList<>();
    ArrayList<Van> vans = new ArrayList<>();
    ArrayList<Elctrogun> elcgun = new ArrayList<>();
    ArrayList<ElectroCar> elc = new ArrayList<>();

    Fire firee;
    Fire firee1;
    ArrayList<Fire> fires = new ArrayList<>();
    ArrayList<Fire> fireselc = new ArrayList<>();
    ArrayList<Benzin> benzins = new ArrayList<>();
    Life[] lives = new Life[6];

    @FXML
    public void initialize() {
        File file = new File("src/main/game/back2.png");
        Image image = new Image(file.toURI().toString());
        ImageView background = new ImageView(image);
        background.setX(0);
        background.setY(-1591);
        background.setFitHeight(2391);
        background.setFitWidth(500);
        pane.getChildren().add(background);


        player = new Player(240, 600, 100, 60, "src/main/game/playerCar.png", pane);
        player.addToPane();
        for (int i = 0; i < 6; i++) {
            lives[i] = new Life(i, pane);
        }
        {
            Timeline machineMove = new Timeline();
            KeyFrame kfmachineMove = new KeyFrame(Duration.millis(100), actionEvent -> {

                time += .1;
                pane.requestFocus();
                pane.setOnKeyPressed(keyEvent -> {
                    if (keyEvent.getCode() == KeyCode.D && player.getX() < 300) {
                        Timeline pg = new Timeline();
                        KeyFrame kg = new KeyFrame(Duration.millis(10), actionEvent12 -> {
                            player.setX(player.getX() + 10);
                        });
                        pg.getKeyFrames().add(kg);
                        pg.setCycleCount(10);
                        pg.play();
                    }
                    if (keyEvent.getCode() == KeyCode.A && player.getX() >= 150) {
                        Timeline pg = new Timeline();
                        KeyFrame kg = new KeyFrame(Duration.millis(10), actionEvent12 -> {
                            player.setX(player.getX() - 10);
                        });
                        pg.getKeyFrames().add(kg);
                        pg.setCycleCount(10);
                        pg.play();
                    }
                    if (keyEvent.getCode() == KeyCode.SPACE) {
                        if (player.ghostmode) {
                            Fire fire = new Fire((int) player.getX(), (int) player.getY(), 140, 65, "src/main/game/fire22.gif", pane);
                            fire.addToPane();
                            fires.add(fire);
                            fire.move(-8, 0);
                            if (fire.getY() <= 0) {
                                fire.removeToPane();
                            }
                        } else {
                            Fire fire = new Fire((int) player.getX(), (int) player.getY(), 140, 55, "src/main/game/blufire1.gif", pane);
                            fire.addToPane();
                            fires.add(fire);
                            fire.move(-8, 0);
                            if (fire.getY() <= 0) {
                                fire.removeToPane();
                            }
                        }

                    }
                });
            });
            machineMove.getKeyFrames().add(kfmachineMove);
            machineMove.setCycleCount(Timeline.INDEFINITE);
            machineMove.play();
        }//                player move

        {
            int[] s = new int[3];
            s[0] = 1;
            s[1] = 2;
            s[2] = 3;
            Timeline timelineasli = new Timeline();
            KeyFrame keyFrame1asli = new KeyFrame(Duration.millis(1000), actionEvent1 -> {

                int d = (int) (Math.random() * 6);

                if (d == 1) {
                    Van van = new Van(50 + (100 * (s[(int) (Math.random() * 3)])), 0, 150, 70, "src/main/images/car1.png", pane);
                    van.addToPane();
                    vans.add(van);
                    van.move();

                    Timeline timeline = new Timeline();
                    KeyFrame keyFrame = new KeyFrame(Duration.millis(100), actionEvent -> {
                        if (van.getY() > 900) {
                            van.removeToPane();
                        }
                    });
                    timeline.getKeyFrames().add(keyFrame);
                    timeline.setCycleCount(Timeline.INDEFINITE);
                    timeline.play();
                }//Van
                if (d == 2) {
                    ElectroCar electroCar = new ElectroCar(50 + (100 * (s[(int) (Math.random() * 3)])), 0, 100, 60, "src/main/game/elcCar_prev_ui.png", pane);
                    electroCar.addToPane();
                    elc.add(electroCar);
                    electroCar.move();
                    Timeline timeline = new Timeline();
                    KeyFrame keyFrame = new KeyFrame(Duration.millis(100), actionEvent -> {
                        if (electroCar.getY() > 900) {
                            electroCar.removeToPane();
                        }
                    });
                    timeline.getKeyFrames().add(keyFrame);
                    timeline.setCycleCount(Timeline.INDEFINITE);
                    timeline.play();



                            Fire firee = new Fire(electroCar.getX() + 30, electroCar.getY(), 22, 22, "src/main/images/im1ages.png", pane);
                            firee.addToPane();
                            firee.move(15, 0);
                            fireselc.add(firee);
                            electroCar.check = false;



                }//elcCar
                if (d == 4) {
                    Elctrogun elcg = new Elctrogun(50 + (100 * (s[(int) (Math.random() * 3)])), 0, 100, 60, "src/main/game/twegun_prev_ui.png", pane);
                    elcg.addToPane();
                    elcgun.add(elcg);
                    elcg.move();
                    Timeline timeline = new Timeline();
                    KeyFrame keyFrame = new KeyFrame(Duration.millis(100), actionEvent -> {
                        if (elcg.getY() > 900) {
                            elcg.removeToPane();
                        }
                    });
                    timeline.getKeyFrames().add(keyFrame);
                    timeline.setCycleCount(Timeline.INDEFINITE);
                    timeline.play();

                    Timeline tv = new Timeline();
                    KeyFrame kv = new KeyFrame(Duration.millis(100), event1 -> {
                        if (elcg.getY() >= 150 && elcg.check) {

                            Fire firee = new Fire(elcg.getX()+25, elcg.getY(), 22, 22, "src/main/images/im1ages.png", pane);
                            firee.addToPane();
                            firee.move(14, -3);
                            fireselc.add(firee);
                            Fire firee1 = new Fire(elcg.getX()+25, elcg.getY(), 22, 22, "src/main/images/im1ages.png", pane);
                            firee1.addToPane();
                            firee1.move(14, 3);
                            fireselc.add(firee1);
                            elcg.check = false;
                        }
                    });
                    tv.getKeyFrames().add(kv);
                    tv.setCycleCount(Timeline.INDEFINITE);
                    tv.play();

                }//elcCargun
                if (d == 3 || d == 5) {
                    Enemey enemey = new Enemey(50 + (100 * (s[(int) (Math.random() * 3)])), 0, 100, 60, "src/main/game/electCar_prev_ui.png", pane);
                    enemey.addToPane();
                    enemey1.add(enemey);
                    enemey.move();
                    Timeline timeline = new Timeline();
                    KeyFrame keyFrame = new KeyFrame(Duration.millis(100), actionEvent -> {
                        if (enemey.getY() > 900) {
                            enemey.removeToPane();
                        }
                    });
                    timeline.getKeyFrames().add(keyFrame);
                    timeline.setCycleCount(Timeline.INDEFINITE);
                    timeline.play();
                }//enemy

            });
            timelineasli.getKeyFrames().add(keyFrame1asli);
            timelineasli.setCycleCount(Timeline.INDEFINITE);
            timelineasli.play();
        }//                van elcCar generate

        {
            int[] s = new int[3];
            s[0] = 1;
            s[1] = 2;
            s[2] = 3;
            Timeline timelineasli = new Timeline();
            KeyFrame keyFrame1asli = new KeyFrame(Duration.millis(6000 + Math.random() * 4), actionEvent1 -> {
                int d = (int) (Math.random() * 4);
                if (d == 1 || d == 4 || d == 5) {

                    Benzin benzin = new Benzin(50 + (100 * (s[(int) (Math.random() * 3)])), 0, 50, 50, "src/main/game/petrol.png", pane);
                    benzin.addToPane();
                    benzins.add(benzin);
                    benzin.move();

                    Timeline timeline = new Timeline();
                    KeyFrame keyFrame = new KeyFrame(Duration.millis(100), actionEvent -> {
                        if (benzin.getY() > 900) {
                            benzin.removeToPane();
                        }
                    });
                    timeline.getKeyFrames().add(keyFrame);
                    timeline.setCycleCount(Timeline.INDEFINITE);
                    timeline.play();
                }//beczin
                if (d == 2) {
                    Coin coin = new Coin(50 + (100 * (s[(int) (Math.random() * 3)])), 0, 70, 70, "src/main/game/coin.gif", pane);
                    coin.addToPane();
                    coins.add(coin);
                    coin.move();

                    Timeline timeline1 = new Timeline();
                    KeyFrame keyFrame1 = new KeyFrame(Duration.millis(100), actionEvent -> {
                        if (coin.getY() > 900) {
                            coin.removeToPane();
                        }
                    });
                    timeline1.getKeyFrames().add(keyFrame1);
                    timeline1.setCycleCount(Timeline.INDEFINITE);
                    timeline1.play();
                }//coin
                if (d == 3) {
                    Booster booster = new Booster(50 + (100 * (s[(int) (Math.random() * 3)])), 0, 70, 70, "src/main/game/boost.gif", pane);
                    booster.addToPane();
                    bs.add(booster);
                    booster.move();
                    Timeline timeline = new Timeline();
                    KeyFrame keyFrame = new KeyFrame(Duration.millis(100), actionEvent -> {
                        if (booster.getY() > 900) {
                            booster.removeToPane();
                        }
                    });
                    timeline.getKeyFrames().add(keyFrame);
                    timeline.setCycleCount(Timeline.INDEFINITE);
                    timeline.play();
                }//booster
            });
            timelineasli.getKeyFrames().add(keyFrame1asli);
            timelineasli.setCycleCount(Timeline.INDEFINITE);
            timelineasli.play();
        }//              benzin coin generate

        {
            Timeline tcheck1 = new Timeline();
            KeyFrame kchech1 = new KeyFrame(Duration.millis(1), actionEvent -> {
                background.setY(background.getY() + .1);

                if (background.getY() >= 0) {

                    pane.getChildren().remove(background);
                    background.setY(-1591);
                    pane.getChildren().addFirst(background);
                }
                checkFireEnemyCollisions();
            });
            tcheck1.getKeyFrames().add(kchech1);
            tcheck1.setCycleCount(Timeline.INDEFINITE);
            tcheck1.play();

            Timeline tcheck = new Timeline();
            KeyFrame kchech = new KeyFrame(Duration.millis(100), actionEvent -> {
                for (Booster booster : bs) {
                    if ((booster.getImageView().intersects(player.getImageView().getLayoutBounds())) && booster.check) {
                        booster.removeToPane();
                        booster.check = false;
                        {
                            player.ghostmode = false;
                            Rectangle rectangle = new Rectangle(0, 730, 500, 20);
                            rectangle.setFill(Color.GOLD);
                            pane.getChildren().add(rectangle);
                            Timeline tcheckr = new Timeline();
                            KeyFrame kchechr = new KeyFrame(Duration.millis(100), actionEventr -> {

                                rectangle.setX(rectangle.getX() - 10);
                            });
                            tcheckr.getKeyFrames().add(kchechr);
                            tcheckr.setCycleCount(Timeline.INDEFINITE);
                            tcheckr.play();
                            if (rectangle.getX() < 0)
                                pane.getChildren().remove(rectangle);
                        }
                        tcheck.stop();
                        PauseTransition pause = new PauseTransition(Duration.seconds(5));
                        pause.setOnFinished(event -> {
                            tcheck.play();
                            player.ghostmode = true;
                        });
                        pause.play();
                    }
                }
                checkConflictLife();
            });
            tcheck.getKeyFrames().add(kchech);
            tcheck.setCycleCount(Timeline.INDEFINITE);
            tcheck.play();

            ////////////////////
            Rectangle rectangle1 = new Rectangle(0, 740, 500, 20);
            rectangle1.setFill(Color.RED);
            pane.getChildren().add(rectangle1);

            Timeline tcheckr = new Timeline();
            KeyFrame kchechr = new KeyFrame(Duration.millis(100), actionEventr -> {
                bpetrol -= .2;
                rectangle1.setX(rectangle1.getX() - 1);
            });
            tcheckr.getKeyFrames().add(kchechr);
            tcheckr.setCycleCount(Timeline.INDEFINITE);
            tcheckr.play();

            boolean[] isConditionMet = {false};

            Timeline tcheck2 = new Timeline();
            KeyFrame kchech2 = new KeyFrame(Duration.millis(100), actionEvent -> {
                for (Benzin benzin : benzins) {
                    if ((benzin.getImageView().intersects(player.getImageView().getLayoutBounds())) && benzin.check) {
                        bpetrol += 20;
                        benzin.check = false;
                        rectangle1.setX(rectangle1.getX() + 100);
                        benzin.removeToPane();
                    }
                }
                if (player.deathcheck) {
                    if (bpetrol <= 0 && !isConditionMet[0]) {
                        isConditionMet[0] = true;
                        for (int i = 0; i < 6; i++) {
                            lives[i].damage();
                        }
                        player.removeToPane();
                        pd();
                        player.death(fusername, score, time, itemdestroy, dt);
                    }
                }
                checkConflict();
            });
            tcheck2.getKeyFrames().add(kchech2);
            tcheck2.setCycleCount(Timeline.INDEFINITE);
            tcheck2.play();

        }//               checkConflict
    }

    private void checkConflict() {
        for (Coin coin : coins) {
            if (coin.getImageView().intersects(player.getImageView().getLayoutBounds())) {
                score += 5;
                tscore.setText(String.valueOf(score));
                coin.removeToPane();
            }

        }
    }

    private void checkConflictLife() {
        for (Enemey enemy : enemey1) {
            if ((enemy.getImageView().intersects(player.getImageView().getLayoutBounds()) && enemy.check)) {
                if (player.life >= 6) {
                    player.life = 5;
                }
                if (player.life >= 5) {
                    player.life++;
                    enemy.check = false;
                    lives[player.life - 1].damage();
                    player.removeToPane();
                    score -= 1;
                    tscore.setText(String.valueOf(score));
                    gc = false;
                    player.deathcheck = false;
                    pd();
                    player.death(fusername, score, time, itemdestroy, dt);
                    enemy.removeToPane1(enemy.getX(), enemy.getY());
                } else {
                    player.life++;
                    enemy.check = false;
                    lives[player.life - 1].damage();
                    enemy.removeToPane1(enemy.getX(), enemy.getY());
                    score -= 1;
                    tscore.setText(String.valueOf(score));
                }
            }
        }
        for (Van van : vans) {
            if ((van.getImageView().intersects(player.getImageView().getLayoutBounds()) && van.check)) {
                if (player.life >= 6) {
                    player.life = 5;
                }
                if (player.life >= 5) {
                    player.life++;
                    van.removeToPane();
                    van.check = false;
                    lives[player.life - 1].damage();
                    player.removeToPane();
                    van.removeToPane1(van.getX(), van.getY());
                    score -= 2;
                    tscore.setText(String.valueOf(score));
                    gc = false;
                    player.deathcheck = false;
                    pd();
                    player.death(fusername, score, time, itemdestroy, dt);


                } else {
                    van.removeToPane1(van.getX(), van.getY());
                    player.life += 2;
                    lives[player.life - 1].damage();
                    lives[player.life - 2].damage();
                    van.check = false;

                    score -= 2;
                    tscore.setText(String.valueOf(score));
                }
            }
        }
        for (ElectroCar electroCar : elc) {
            if ((electroCar.getImageView().intersects(player.getImageView().getLayoutBounds()) && electroCar.check)) {
                if (player.life >= 6) {
                    player.life = 5;
                }
                if (player.life >= 5) {
                    player.life++;
                    electroCar.removeToPane1(electroCar.getX(), electroCar.getY());
                    electroCar.check = false;
                    lives[player.life - 1].damage();
                    player.removeToPane();
                    player.deathcheck = false;
                    score -= 2;
                    tscore.setText(String.valueOf(score));
                    gc = false;
                    player.death(fusername, score, time, itemdestroy, dt);
                    pd();

                } else {
                    player.life++;
                    electroCar.check = false;
                    electroCar.removeToPane1(electroCar.getX(), electroCar.getY());
                    lives[player.life - 1].damage();
                    score -= 3;
                    tscore.setText(String.valueOf(score));
                }
            }

        }
        for (Elctrogun electroCar1 : elcgun) {
            if ((electroCar1.getImageView().intersects(player.getImageView().getLayoutBounds()) && electroCar1.check)) {
                if (player.life >= 6) {
                    player.life = 5;
                }
                if (player.life >= 5) {
                    player.life++;
                    electroCar1.removeToPane1(electroCar1.getX(), electroCar1.getY());
                    electroCar1.check = false;
                    lives[player.life - 1].damage();
                    player.removeToPane();
                    player.deathcheck = false;
                    score -= 2;
                    tscore.setText(String.valueOf(score));
                    gc = false;
                    player.death(fusername, score, time, itemdestroy, dt);
                    pd();

                } else {
                    player.life += 3;
                    electroCar1.check = false;
                    lives[player.life - 3].damage();
                    lives[player.life - 2].damage();
                    electroCar1.removeToPane1(electroCar1.getX(), electroCar1.getY());
                    lives[player.life - 1].damage();
                    score -= 3;
                    tscore.setText(String.valueOf(score));
                }
            }

        }
        for (Fire firee : fireselc) {
            if ((firee.getImageView().intersects(player.getImageView().getLayoutBounds())) && firee.check) {
                if (player.life >= 6) {
                    player.life = 5;
                }
                if (player.life >= 5) {
                    player.life++;
                    lives[player.life - 1].damage();
                    player.deathcheck = false;
                    player.removeToPane();
                    score--;
                    firee.check = false;
                    tscore.setText(String.valueOf(score));
                    gc = false;
                    player.death(fusername, score, time, itemdestroy, dt);
                    firee.removeToPane();
                    pd();


                } else {
                    player.life++;
                    lives[player.life - 1].damage();
                    firee.check = false;
                    score--;
                    firee.removeToPane();
                    tscore.setText(String.valueOf(score));
                    firee.removeToPane();
                }
            }

        }

    }

    private void checkFireEnemyCollisions() {
        for (Fire fire : fires) {
            for (Enemey enemy : enemey1) {
                if (fire.getImageView().intersects(enemy.getImageView().getLayoutBounds())) {
                    enemy.removeToPane1(enemy.getX(), enemy.getY());
                    fire.removeToPane();
                    score += 2;
                    itemdestroy++;
                    tscore.setText(String.valueOf(score));
                }
            }
        }//player shot
        for (Fire fire1 : fires) {
            for (ElectroCar electroCar : elc) {
                if ((fire1.getImageView().intersects(electroCar.getImageView().getLayoutBounds())) && fire1.check) {
                    electroCar.removeToPane1(electroCar.getX(), electroCar.getY());
                    fire1.check = false;
                    fire1.removeToPane();
                    itemdestroy++;
                    score--;
                    tscore.setText(String.valueOf(score));
                }
            }
        }//reflect of fire and elc
        for (Fire fire1 : fires) {
            for (Elctrogun electroCar : elcgun) {
                if ((fire1.getImageView().intersects(electroCar.getImageView().getLayoutBounds())) && fire1.check) {
                    electroCar.removeToPane1(electroCar.getX(), electroCar.getY());
                    fire1.check = false;
                    fire1.removeToPane();
                    itemdestroy++;
                    score--;
                    tscore.setText(String.valueOf(score));
                }
            }
        }//reflect of fire and elc
        for (Fire fire2 : fires) {
            for (Van van : vans) {
                if (fire2.getImageView().intersects(van.getImageView().getLayoutBounds())) {
                    van.removeToPane1(van.getX(), van.getY());
                    fire2.removeToPane();
                    itemdestroy++;
                    score += 2;
                    tscore.setText(String.valueOf(score));
                }
            }
        }//reflect of fire and vans
    }

    public void pd() {
        player.setX(-600);
        player.setY(-600);

    }
}