package com.class_package;

public class Interface1 {
    public static void main(String[] args) {
        // Constructor injection
        IChocoManufacturer company1 = new Hershey();
        var manufacturer1 = new ChocoManufacturer(company1); // var manufacturer1 = new ChocoManufacturer(new Hershey()); can also give directly
        manufacturer1.details();

        // Setter injection
        var company2 = new Cadbury();
        manufacturer1.setManufacturer(company2); // manufacturer1.setManufacturer(new Cadbury()); can also give directly
        manufacturer1.details();

        // Method injection
        manufacturer1.details(new Nestle());

        // Can do like this also
        /*
        // Setter injection
        var company2 = new Cadbury();
        var manufacturer2 = new ChocoManufacturer();
        manufacturer2.setManufacturer(company2);
        manufacturer2.details();

        // Method injection
        var manufacturer3 = new ChocoManufacturer();
        manufacturer3.details(new Nestle());
        */
    }
}

interface IChocoManufacturer{
    String name();
    int orders();
    void revenue();
}

class ChocoManufacturer{
    private IChocoManufacturer manufacturer;

    private String name;
    private int ord;

    public ChocoManufacturer(){
        // dummy for not showing errors to implement setter, method injection
    }

    // Constructor injection
    public ChocoManufacturer(IChocoManufacturer manufacturer) {
        this.manufacturer = manufacturer;
    }

    // Setter injection
    public void setManufacturer(IChocoManufacturer manufacturer) {
        this.manufacturer = manufacturer;
    }

    public void details(){
        name= manufacturer.name();
        System.out.println("Manufacturer name : "+name);
        ord= manufacturer.orders();
        System.out.println("Orders : "+ord);
        manufacturer.revenue();
    }

    // Method injection
    public void details(IChocoManufacturer manufacturer){
        name= manufacturer.name();
        System.out.println("Manufacturer name : "+name);
        ord= manufacturer.orders();
        System.out.println("Orders : "+ord);
        manufacturer.revenue();
    }
}

class Hershey implements IChocoManufacturer{

    @Override
    public String name() {
        return "Hershey";
    }

    @Override
    public int orders() {
        return 1000;
    }

    @Override
    public void revenue() {
        System.out.println("Revenue : "+5000);
    }
}

class Cadbury implements IChocoManufacturer{

    @Override
    public String name() {
        return "Cadbury";
    }

    @Override
    public int orders() {
        return 2000;
    }

    @Override
    public void revenue() {
        System.out.println("Revenue : "+3000);
    }
}

class Nestle implements IChocoManufacturer{

    @Override
    public String name() {
        return "Nestle";
    }

    @Override
    public int orders() {
        return 4000;
    }

    @Override
    public void revenue() {
        System.out.println("Revenue : "+3000);
    }
}