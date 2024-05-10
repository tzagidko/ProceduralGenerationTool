// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VoronoiGeneratorLibrary.h"
#include "GenerateVoronoiDiagram.generated.h"

UCLASS()
class PROCEDURALGENERATION_API AGenerateVoronoiDiagram : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGenerateVoronoiDiagram();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void GenerateDiagram();
	UPROPERTY(EditAnywhere, Category="Voronoi")
	TArray<FVoronoiPoint> VoronoiPoints;
	UPROPERTY(EditAnywhere, Category="Voronoi")
	float MinX;
	UPROPERTY(EditAnywhere, Category="Voronoi")
	float MaxX;
	UPROPERTY(EditAnywhere, Category="Voronoi")
	float MinY;
	UPROPERTY(EditAnywhere, Category="Voronoi")
	float MaxY;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	void VisualizeVoronoiDiagram(const TArray<FVoronoiCell>&Cells);

};
