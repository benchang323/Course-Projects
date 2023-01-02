package S2.LiverExchange;

public class Donor extends Person
{
    //Attributes
    private int donateTo;
    private int pairedWith;
    
    //Constructor
    public Donor(int id, String name, String dob, bloodType blood, double longitude, double latitude, int donateTo)
    {
        super(id, name, dob, blood, longitude, latitude);
        this.donateTo = donateTo;
    }

    //Getters
    public int getDonateTo() 
    {
        return donateTo;
    }

    public int getPairedWith() 
    {
        return pairedWith;
    }

    //Setters
    public void setDonateTo(int donateTo) 
    {
        this.donateTo = donateTo;
    }

    public void setPairedWith(int pairedWith) 
    {
        this.pairedWith = pairedWith;
    }

    @Override
    public String toString() 
    {
        return "Donor[id=" + super.getId() + ", name=" + super.getName() + ", dob=" + super.getDob() + ", blood=" + super.getBlood() + ", longitude=" + super.getLongitude() + ", latitude=" + super.getLatitude() + ", donateTo=" + donateTo + ", pairedWith=" + pairedWith + ']';
    }
}
/* 
    Donor has DonateTo and Pairing 
*/