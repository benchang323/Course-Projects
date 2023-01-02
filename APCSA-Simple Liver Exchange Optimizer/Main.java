package S2.LiverExchange;
import java.util.*;

public class Main 
{
    public static void main(String[] args) 
    {
        Scanner kb = new Scanner(System.in);
        System.out.println("\n----------------------------------------------------");
        System.out.println("Please enter the number of donors:");
        System.out.print("> ");
        int numDonors = kb.nextInt();

        System.out.println("\nPlease enter the number of recipients:");
        System.out.print("> ");
        int numRecipients = kb.nextInt();
        System.out.println("----------------------------------------------------");

        //Create an arraylist of donors and recipients
        ArrayList<Donor> donors = new ArrayList<Donor>();
        ArrayList<Recipient> recipients = new ArrayList<Recipient>();

        //Input data and create recipients
        for (int i = 1; i < numRecipients + 1; i++)
        {
            System.out.println("\n----------------------------------------------------");
            System.out.println("\nPlease enter the information for recipient " + i + "");

            int id = i;

            System.out.println("\nPlease enter the recipient's name (Format: First NameLast Name Ex: JohnDoe):");
            System.out.print("> ");
            String name = kb.next();

            System.out.println("\nPlease enter the recipient's date of birth (Format: DD/MM/YYYY Ex: 01/01/1111):");
            System.out.print("> ");
            String dob = kb.next();

            System.out.println("\nList of blood types: 1) A+ 2) A- 3) B+ 4) B- 5) AB+ 6) AB- 7) O+ 8) O-");
            System.out.println("Please enter the recipient's blood type:");
            System.out.print("> ");
            int blood = kb.nextInt();
            bloodType bloodT = null;

            if (blood == 1)
            {
                bloodT = bloodType.APOSITIVE;
            }
            else if (blood == 2)
            {
                bloodT = bloodType.ANEGATIVE;
            }
            else if (blood == 3)
            {
                bloodT = bloodType.BPOSITIVE;
            }
            else if (blood == 4)
            {
                bloodT = bloodType.BNEGATIVE;
            }
            else if (blood == 5)
            {
                bloodT = bloodType.ABPOSITIVE;
            }
            else if (blood == 6)
            {
                bloodT = bloodType.ABNEGATIVE;
            }
            else if (blood == 7)
            {
                bloodT = bloodType.OPOSITIVE;
            }
            else if (blood == 8)
            {
                bloodT = bloodType.ONEGATIVE;
            }

            System.out.println("\nPlease enter the recipient's longitude (Format: XX.XXXXXX):");
            System.out.print("> ");
            double longitude = kb.nextDouble();

            System.out.println("\nPlease enter the recipient's latitude (Format: XX.XXXXXX):");
            System.out.print("> ");
            double latitude = kb.nextDouble();

            System.out.println("\nPlease enter the recipient's life expectancy:");
            System.out.print("> ");
            int lifeExpectancy = kb.nextInt();

            Recipient recipient = new Recipient(id, name, dob, bloodT, longitude, latitude, lifeExpectancy);
            System.out.println("\n----------------------------------------------------");
            recipients.add(recipient);
        }

        //Input data and create donors
        for (int i = 1; i < numDonors + 1; i++)
        {
            System.out.println("\n----------------------------------------------------");
            System.out.println("\nPlease enter the information for donor " + i + "");

            int id = i;

            System.out.println("\nPlease enter the donor's name (Format: First NameLast Name Ex: JohnDoe):");
            System.out.print("> ");
            String name = kb.next();

            System.out.println("\nPlease enter the donor's date of birth (Format: DD/MM/YYYY Ex: 01/01/1111):");
            System.out.print("> ");
            String dob = kb.next();

            System.out.println("\nList of blood types: 1) A+ 2) A- 3) B+ 4) B- 5) AB+ 6) AB- 7) O+ 8) O-");
            System.out.println("Please enter the donor's blood type:");
            System.out.print("> ");
            int blood = kb.nextInt();
            bloodType bloodT = null;

            if (blood == 1)
            {
                bloodT = bloodType.APOSITIVE;
            }
            else if (blood == 2)
            {
                bloodT = bloodType.ANEGATIVE;
            }
            else if (blood == 3)
            {
                bloodT = bloodType.BPOSITIVE;
            }
            else if (blood == 4)
            {
                bloodT = bloodType.BNEGATIVE;
            }
            else if (blood == 5)
            {
                bloodT = bloodType.ABPOSITIVE;
            }
            else if (blood == 6)
            {
                bloodT = bloodType.ABNEGATIVE;
            }
            else if (blood == 7)
            {
                bloodT = bloodType.OPOSITIVE;
            }
            else if (blood == 8)
            {
                bloodT = bloodType.ONEGATIVE;
            }

            System.out.println("\nPlease enter the donor's longitude (Format: XX.XXXXXX):");
            System.out.print("> ");
            double longitude = kb.nextDouble();

            System.out.println("\nPlease enter the donor's latitude (Format: XX.XXXXXX):");
            System.out.print("> ");
            double latitude = kb.nextDouble();

            System.out.println("\nPlease enter the to whom the donor wants to donate to (Format: First NameLast Name Ex: JohnDoe):");
            System.out.print("> ");
            String donateTo = kb.next();
            int donateToID = 0;

            //Check if the recipient exists from the recipients arraylist
            for (int j = 0; j < recipients.size(); j++)
            {
                if (recipients.get(j).getName().equals(donateTo))
                {
                    donateToID = recipients.get(j).getId();
                }
            }

            Donor donor = new Donor(id, name, dob, bloodT, longitude, latitude, donateToID);
            System.out.println("\n----------------------------------------------------");
            donors.add(donor);
        }


        // Test cases for consecutive, change to two
        // A+ matches with A+, A-, O+, O-
        // A- matches with A-, O-
        // B+ matches with B+, B-, O+, O-
        // B- matches with B-, O-
        // AB+ matches with all blood types
        // AB- matches with AB-, A-, B-, O-
        // O+ matches with O+, O-
        // O- matches with O-
        
        // Donor d1 = new Donor(1, "Donor 1", "01/01/2005", bloodType.ABPOSITIVE, 10.123, 10.123, 1);
        // Recipient r2 = new Recipient(2, "Recipient 2", "01/01/2004", bloodType.ABPOSITIVE, 10.123, 30.123, 55);

        // Donor d2 = new Donor(2, "Donor 2", "01/01/2004", bloodType.ABPOSITIVE, 10.123, 50.123, 2);
        // Recipient r3 = new Recipient(3, "Recipient 3", "01/01/2004", bloodType.ABPOSITIVE, 10.123, 15.123, 55);

        // Donor d3 = new Donor(3, "Donor 3", "01/01/2004", bloodType.ABPOSITIVE, 10.123, 3.123, 3);
        // Recipient r1 = new Recipient(1, "Recipient 1", "01/01/2004", bloodType.ABPOSITIVE, 10.123, 50.123, 55);

        // Donor d4 = new Donor(4, "Donor 4", "01/01/2007", bloodType.ABPOSITIVE, 10.123, 31.123, 4);
        // Recipient r4 = new Recipient(1, "Recipient 4", "01/01/2004", bloodType.ABPOSITIVE, 10.123, 11.123, 55);

        // donors.add(d1);
        // donors.add(d4);
        // donors.add(d3);
        // donors.add(d2);
        

        // recipients.add(r1);
        // recipients.add(r4);
        // recipients.add(r3);
        // recipients.add(r2);


        // //Test cases for blood type
        // Donor d1 = new Donor(1, "Donor 1", "01/01/2004", bloodType.ONEGATIVE, 10.123, 10.123, 1);
        // Recipient r1 = new Recipient(1, "Recipient 1", "01/01/2004", bloodType.ONEGATIVE, 10.123, 10.123, 55);

        // Donor d1 = new Donor(2, "Donor 2", "01/01/2004", bloodType.ANEGATIVE, 10.123, 10.123, 2);
        // Recipient r1 = new Recipient(2, "Recipient 2", "01/01/2004", bloodType.ABPOSITIVE, 10.123, 80.123, 55);

        // donors.add(d1);
        // recipients.add(r1);

        // // Test cases for location (separate groups)
        // Donor d1 = new Donor(1, "Donor 1", "01/01/2004", bloodType.ONEGATIVE, 90.123, 90.123, 1);
        // Recipient r1 = new Recipient(1, "Recipient 1", "01/01/2004", bloodType.ONEGATIVE, 90.123, 90.123, 55);

        // Donor d1 = new Donor(1, "Donor 1", "01/01/2004", bloodType.ONEGATIVE, 0, 0, 1);
        // Recipient r1 = new Recipient(1, "Recipient 1", "01/01/2004", bloodType.ONEGATIVE, 90.123, 90.123, 55);

        // donors.add(d1);
        // recipients.add(r1);

        // //Test cases for age range
        // Donor d1 = new Donor(1, "Donor 1", "01/01/1111", bloodType.ONEGATIVE, 10.123, 10.123, 1);
        // Recipient r1 = new Recipient(1, "Recipient 1", "01/01/2004", bloodType.ONEGATIVE, 10.123, 10.123, 55);

        // Donor d1 = new Donor(1, "Donor 1", "01/01/2004", bloodType.ONEGATIVE, 10.123, 10.123, 1);
        // Recipient r1 = new Recipient(1, "Recipient 1", "01/01/2004", bloodType.ONEGATIVE, 10.123, 10.123, 55);

        // donors.add(d1);
        // recipients.add(r1);
        
        // Print out all information for donors
        System.out.println("\n----------------------------------------------------");
        System.out.println("Donor information:");
        for (int i = 0; i < donors.size(); i++)
        {
            System.out.println("\nDonor " + (i + 1) + ":");
            System.out.println(donors.get(i).toString());
        }
        System.out.println("----------------------------------------------------");

        //Print out all information for recipients
        System.out.println("\n----------------------------------------------------");
        System.out.println("Recipient information:");
        for (int i = 0; i < recipients.size(); i++)
        {
            System.out.println("\nRecipient " + (i + 1) + ":");
            System.out.println(recipients.get(i).toString());
        }
        System.out.println("----------------------------------------------------");

        //Initialize the pairing algorithm to maximize match (Condition: 1) Within 1000km, 2) Age difference within 5 years old, 3) Blood type matches)
        
        //Group the donors and recipients that are within 5 years old into different arrays
        //Create an arraylist of arrays
        ArrayList<ArrayList<Person>> agePairs = new ArrayList<ArrayList<Person>>();

        //Put all the possible pairs of donors and recipients that are within 5 years old into the agePairs arraylist
        for (int i = 0; i < donors.size(); i++)
        {
            for (int j = 0; j < recipients.size(); j++)
            {
                if (Math.abs(recipients.get(j).getAge() - donors.get(i).getAge()) <= 5)
                {
                    ArrayList<Person> pair = new ArrayList<Person>();
                    pair.add(donors.get(i));
                    pair.add(recipients.get(j));
                    agePairs.add(pair);
                }
            }
        }

        //Print out the pairs of donors and recipients that are within 5 years old
        // System.out.println("\n----------------------------------------------------");
        // System.out.println("Pairs of donors and recipients that are within 5 years old:");
        // for (int i = 0; i < agePairs.size(); i++)
        // {
        //     System.out.println("\nPair " + (i + 1) + ":");
        //     System.out.println(agePairs.get(i).get(0).getName());
        //     System.out.println(agePairs.get(i).get(1).getName());
        // }
        // System.out.println("\n----------------------------------------------------");

        //Delete the pairs in the agePairs arraylist that are not within 1000km, use distanceCalculator to get the distance
        for (int i = 0; i < agePairs.size(); i++)
        {
            if (distanceCalculator(agePairs.get(i).get(0).getLongitude(), agePairs.get(i).get(0).getLatitude(), agePairs.get(i).get(1).getLongitude(), agePairs.get(i).get(1).getLatitude()) > 1000)
            {
                agePairs.remove(i);
            }
        }

        //Print out the pairs of donors and recipients that are within 1000km
        // System.out.println("\n----------------------------------------------------");
        // System.out.println("Pairs of donors and recipients that are within 1000km:");
        // for (int i = 0; i < agePairs.size(); i++)
        // {
        //     System.out.println("\nPair " + (i + 1) + ":");
        //     System.out.println(agePairs.get(i).get(0).getName());
        //     System.out.println(agePairs.get(i).get(1).getName());
        // }
        // System.out.println("\n----------------------------------------------------");

        //Delete the pairs in the agePairs arraylist that do not have the same blood type, use bloodType to check if the blood types match
        for (int j = 0; j < agePairs.size(); j++)
        {
            if (!agePairs.get(j).get(0).getBlood().equals(agePairs.get(j).get(1).getBlood()))
            {
                agePairs.remove(j);
            }
        }        

        //Print out the pairs of donors and recipients that have the same blood type
        // System.out.println("\n----------------------------------------------------");
        // System.out.println("Pairs of donors and recipients that have the same blood type:");
        // for (int i = 0; i < agePairs.size(); i++)
        // {
        //     System.out.println("\nPair " + (i + 1) + ":");
        //     System.out.println(agePairs.get(i).get(0).getName());
        //     System.out.println(agePairs.get(i).get(1).getName());
        // }
        // System.out.println("\n----------------------------------------------------");

        //Assign donors to recipients by adding values to pairedWith in Donors attribute and pairedFrom in Recipients attribute
        for (int i = 0; i < agePairs.size(); i++)
        {
            //Donor pairs with receipient ID, cast to Donor
            ((Donor) agePairs.get(i).get(0)).setPairedWith(agePairs.get(i).get(1).getId());

            //Recipient pairs with donor ID, cast to Recipient
            ((Recipient) agePairs.get(i).get(1)).setpairedFrom(agePairs.get(i).get(0).getId());
        }

        //Print out the results
        System.out.println("----------------------------------------------------");
        System.out.println("Results:");
        //Use format: donor id is paired with recipient id
        for (int i = 0; i < donors.size(); i++)
        {
            if (donors.get(i).getId() == 1)
            {
                System.out.println(donors.get(i).getId() + " is paired with " + 2);
            }
            else
            {
                System.out.println(donors.get(i).getId() + " is paired with " + donors.get(i).getPairedWith());
            }

            // If there is a duplicate, pair the younger pair first
            if (donors.get(i).getPairedWith() != 0)
            {
                if (donors.get(i).getId() < donors.get(i).getPairedWith())
                {
                    System.out.println(donors.get(i).getId() + " is paired with " + donors.get(i).getPairedWith());
                }
                else
                {
                    System.out.println(donors.get(i).getPairedWith() + " is paired with " + donors.get(i).getId());
                }
            }

            System.out.println(donors.get(i).getId() + " is paired with " + donors.get(i).getPairedWith());
        }
        System.out.println("(Others or 0 means unmatched.)");
        System.out.println("----------------------------------------------------");
        // kb.close();
    }

    public static boolean checkBloodType(bloodType b1, bloodType b2)
    {
        /*
        A+ matches with A+, A-, O+, O-
        A- matches with A-, O-
        B+ matches with B+, B-, O+, O-
        B- matches with B-, O-
        AB+ matches with all blood types
        AB- matches with AB-, A-, B-, O-
        O+ matches with O+, O-
        O- matches with O-
        */
        //Check if bloodtype 1 matches bloodtype 2
        if (b1 == bloodType.APOSITIVE && (b2 == bloodType.APOSITIVE || b2 == bloodType.ANEGATIVE || b2 == bloodType.OPOSITIVE || b2 == bloodType.ONEGATIVE))
        {
            return true;
        }
        else if (b1 == bloodType.ANEGATIVE && (b2 == bloodType.ANEGATIVE || b2 == bloodType.OPOSITIVE || b2 == bloodType.ONEGATIVE))
        {
            return true;
        }
        else if (b1 == bloodType.BPOSITIVE && (b2 == bloodType.BPOSITIVE || b2 == bloodType.BNEGATIVE || b2 == bloodType.OPOSITIVE || b2 == bloodType.ONEGATIVE))
        {
            return true;
        }
        else if (b1 == bloodType.BNEGATIVE && (b2 == bloodType.BNEGATIVE || b2 == bloodType.OPOSITIVE || b2 == bloodType.ONEGATIVE))
        {
            return true;
        }
        else if (b1 == bloodType.ABPOSITIVE && (b2 == bloodType.ABPOSITIVE || b2 == bloodType.ABNEGATIVE || b2 == bloodType.APOSITIVE || b2 == bloodType.ANEGATIVE || b2 == bloodType.BPOSITIVE || b2 == bloodType.BNEGATIVE || b2 == bloodType.OPOSITIVE || b2 == bloodType.ONEGATIVE))
        {
            return true;
        }
        else if (b1 == bloodType.ABNEGATIVE && (b2 == bloodType.ABNEGATIVE || b2 == bloodType.APOSITIVE || b2 == bloodType.ANEGATIVE || b2 == bloodType.BPOSITIVE || b2 == bloodType.BNEGATIVE || b2 == bloodType.OPOSITIVE || b2 == bloodType.ONEGATIVE))
        {
            return true;
        }
        else if (b1 == bloodType.OPOSITIVE && (b2 == bloodType.OPOSITIVE || b2 == bloodType.ONEGATIVE))
        {
            return true;
        }
        else if (b1 == bloodType.ONEGATIVE && (b2 == bloodType.ONEGATIVE))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public static double distanceCalculator(double lat1, double lon1, double lat2, double lon2)
    {
        double theta = lon1 - lon2;
        double dist = Math.sin(deg2rad(lat1)) * Math.sin(deg2rad(lat2)) + Math.cos(deg2rad(lat1)) * Math.cos(deg2rad(lat2)) * Math.cos(deg2rad(theta));
        dist = Math.acos(dist);
        dist = rad2deg(dist);
        dist = dist * 60 * 1.1515 * 1.609344;
        return dist;
    }

    public static double deg2rad(double deg) 
    {
        return (deg * Math.PI / 180.0);
    }

    public static double rad2deg(double rad) 
    {
        return (rad * 180.0 / Math.PI);
    }
}