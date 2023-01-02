package S2.LiverExchange;

public class Person 
{
    //Attributes
    protected int id;
    protected String name;
    protected String dob;
    protected bloodType blood;
    protected double longitude;
    protected double latitude;
    
    //Constructor
    public Person(int id, String name, String dob, bloodType blood, double longitude, double latitude)
    {
        this.id = id;
        this.name = name;
        this.dob = dob;
        this.blood = blood;
        this.longitude = longitude;
        this.latitude = latitude;
    }

    //Getters
    public int getId() 
    {
        return id;
    }

    public String getName() 
    {
        return name;
    }

    public String getDob() 
    {
        return dob;
    }

    public bloodType getBlood() 
    {
        return blood;
    }

    public double getLongitude() 
    {
        return longitude;
    }

    public double getLatitude() 
    {
        return latitude;
    }

    public int getAge()
    {
        //Get age from dob
        String[] dobSplit = dob.split("/");
        int dobMonth = Integer.parseInt(dobSplit[0]);
        int dobDay = Integer.parseInt(dobSplit[1]);
        int dobYear = Integer.parseInt(dobSplit[2]);

        //Get current date
        java.util.Date date = new java.util.Date();
        int currentMonth = date.getMonth() + 1;
        int currentDay = date.getDate();
        int currentYear = date.getYear() + 1900;

        //Calculate age
        int age = currentYear - dobYear;
        if (currentMonth < dobMonth)
        {
            age--;
        }
        else if (currentMonth == dobMonth)
        {
            if (currentDay < dobDay)
            {
                age--;
            }
        }

        return age;
    }

    //Setters
    public void setId(int id) 
    {
        this.id = id;
    }

    public void setName(String name) 
    {
        this.name = name;
    }

    public void setDob(String dob) 
    {
        this.dob = dob;
    }

    public void setBlood(bloodType blood) 
    {
        this.blood = blood;
    }

    public void setLongitude(double longitude) 
    {
        this.longitude = longitude;
    }

    public void setLatitude(double latitude) 
    {
        this.latitude = latitude;
    }

    public String toString() 
    {
        return "Person[ id=" + id + ", name=" + name + ", dob=" + dob + ", blood=" + blood + ", longitude=" + longitude + ", latitude=" + latitude + " ]";
    }

}

enum bloodType 
{
    APOSITIVE,
    ANEGATIVE,
    BPOSITIVE,
    BNEGATIVE,
    ABPOSITIVE,
    ABNEGATIVE,
    OPOSITIVE,
    ONEGATIVE
};