
const registerUser=async(userData)=>{
    try{
    const response=await axios.post('https://jsonplaceholder.typicode.com/users',userData)
        console.log(response.data);
    }catch(err){
        console.log(err);
    }
    
    
}

// registerUser({ name: "Alice", email: "alice@example.com", password: "secure123" });

// Example usage
registerUser({ name: "Alice", email: "alice@example.com" });
