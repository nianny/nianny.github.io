db.collection('cafes').get().then((snapshot) => {
    //snapshot
    console.log(snapshot.docs)
}) //ascrynous -> its going to complete some time in the future (gives a promise)
