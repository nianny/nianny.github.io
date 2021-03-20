//
//  ContentView.swift
//  WeSplita
//
//  Created by Xiao Nianhe on 20/3/21.
//

import SwiftUI //use functionalities of SwiftUI

struct ContentView: View {
    @State private var tapCount = 0
    //without the @state thing, this gives an error
    /*
     This is because ContentView is a struct, and a struct might be called with the let call, making it a constant
     Therefore, when changing a value inside the struct as the code runs, Swift will give an error
     Furthermore, using the "mutating" keyword doesn't work either as it only works on functions, not variables
     
     
     So therefore, there is this "@State" thing.
     It gives the variable "superpowers", storing it elsewhere
     
     It stores the program state, while keeping the structs small and simple allows better performance
     @State is for simple properties that are stored in one view
     */
    
    
    @State private var name = ""
    
    var body: some View {
        NavigationView{
            Form{
                TextField("Enter your name", text: $name)
                /*
                 Now, you might be wondering, what does this TextField thing do and what does that dollar sign mean
                 
                 Basically, in a textfield you need some place to store the variable that the user inputs
                 This can be done via "@State private var"
                 
                 However, it is not done yet.
                 We need to tell Swift to differentiate between reading the value, and also writing any changes back to the property
                 This is called a two-way binding
                 
                 
                 
                 
                 In the case of our text field,
                 Swift needs to make sure whatever is in the text is also in the name property,
                 so that it can fulfill its promise that our views are a function of their state –
                 that everything the user can see is just the visible representation of the structs and properties in our code.

                 */
                
                Text("Your name is \(name)") // no $ sign, only read but not written back
            }
//            Form{
//                Section{
//                    Text("Hello, world!")
//                    Text("Hello, world!")
//                    Text("Hello, world!")
//                    Text("Hello, world!")
//                    Text("Hello, world!")
//                }
//            }
//            .navigationBarTitle(Text("SwiftUI"), displayMode: .inline)
            
            //alternatively, a simpler way for a large font is
             //.navigationBarTitle("SwiftUI")
            
            Button("Tap Count \(tapCount)"){
                self.tapCount += 1
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
