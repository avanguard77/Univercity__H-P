package com.example.demo38;

import java.util.Date;

public class UserData {
    private int score;
    private double time ;
    private int id;
    private String date;

    public UserData(int score, double time, int id, String date) {
        this.score = score;
        this.time = time;
        this.id = id;
        this.date = date;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }

    public double getTime() {
        return time;
    }

    public void setTime(int time) {
        this.time = time;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    @Override
    public String toString() {
        return STR."UserData{score=\{score}, time=\{time}, id=\{id}, date=\{date}\{'}'}";
    }
}
