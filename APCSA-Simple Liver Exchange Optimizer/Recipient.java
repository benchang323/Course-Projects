package S2.LiverExchange;

public class Recipient extends Person
{
    //Attributes
    private double lifeExpectancy;
    private int pairedFrom;
    
    //Constructor
    public Recipient(int id, String name, String dob, bloodType blood, double longitude, double latitude, double lifeExpectancy)
    {
        super(id, name, dob, blood, longitude, latitude);
        this.lifeExpectancy = lifeExpectancy;
    }
    
    //Getters
    public double getLifeExpectancy()
    {
        return lifeExpectancy;
    }
    
    public int getpairedFrom()
    {
        return pairedFrom;
    }
    
    //Setters
    public void setLifeExpectancy(double lifeExpectancy)
    {
        this.lifeExpectancy = lifeExpectancy;
    }
    
    public void setpairedFrom(int pairedFrom)
    {
        this.pairedFrom = pairedFrom;
    }

    @Override
    public String toString()
    {
        return "Recipient[id=" + super.getId() + ", name=" + super.getName() + ", dob=" + super.getDob() + ", blood=" + super.getBlood() + ", longitude=" + super.getLongitude() + ", latitude=" + super.getLatitude() + ", lifeExpectancy=" + lifeExpectancy + ", pairedFrom=" + pairedFrom + ']';
    }
}
/*
    Recipient has Pairing pairedFrom and LifeExpectancy
*/